/*
	����������ʵ��9������
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<random> // rand(), srand();
#include<ctime>
#include <chrono> // C++ ��΢�뼶���
#include<Windows.h>

using namespace std;

enum class Sorts {
	Bobble,
	Quick,
	Insert,
	Shell,
	Choose,
	Merge,
	Heap,
	Count,
	Redix
};

/***** �����㷨 *****/
// 1 ð������,ʱ�临�Ӷ� n^2
void Bobble_Sort(vector<int> &vec) {
	for (int i = 0; i < vec.size()-1; i++) {
		for (int j = i+1; j < vec.size(); j++) {
			if (vec[j] < vec[i]) swap(vec[j], vec[i]);
		}
	}
}
// 2 ����, ʱ�临�Ӷ�  nlogn
// ����1�����������У�����2������������±ꣻ����3���������Ҷ��±�
void Quick_Sort(vector<int>& vec, int l, int r) {
	if (l >= r)return;
	int base_val = vec[l];
	int left = l;
	int right = r;
	bool flag = false;
	while (l!=r){
		if (flag == false) {
			if (vec[r] < base_val) {
				vec[l] = vec[r];
				l++;
				flag = true;
			}else {
				r--;
			}
		}else {
			if (vec[l] > base_val) {
				vec[r] = vec[l];
				r--;
				flag = false;
			}else {
				l++;
			}
		}
	}
	vec[l] = base_val;
	Quick_Sort(vec, left, l); //ע�����Ի�׼��λ��Ϊ����
	Quick_Sort(vec, l + 1, right);
}
// ��������, ʱ�临�Ӷ� n^2
void Insert_Sort(vector<int>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (vec[j + 1] < vec[j]) swap(vec[j + 1], vec[j]);
			else break;
		}
	}
}
// ϣ������ ʱ�临�Ӷ� Ϊ n^1.3
// ����2��Ϊ�ֶ�����ķֶ�
void Shell_Sort(vector<int> &vec, int n) {
	while (n!= 0){
		for (int k = 0; k < n; k++) {
			for (int i = n; i < vec.size(); i += n) {
				for (int j = i - n; j >= 0; j-=n ) {
					if (vec[j+n] < vec[j])swap(vec[j], vec[j + n]);
					else break;
				}
			}
		}
		n = n / 2;
	}
}
// ѡ������, ʱ�临�Ӷ�Ϊ n^2, ѡ����СԪ��
void Choose_Sort(vector<int>& vec) {
	for (int i = 0; i < vec.size()-1; i++) {
		int min = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[min]) min = j;
		}
		swap(vec[min], vec[i]);
	}
}
// �鲢����ʱ�临�Ӷ�Ϊ nlogn
// ����2����ʱ���� ����3������±�; ����4���Ҷ��±�
void Merge_Sort(vector<int> &vec, vector<int> &tmp, int l, int r) {
	if (l >= r) return;
	int left1 = l;
	int right1 = (l + r) / 2;
	int left2 = right1 + 1;
	int right2 = r;
	Merge_Sort(vec, tmp, left1, right1);
	Merge_Sort(vec, tmp, left2, right2);

	int k = l;// ������Ҫ�±�Ϊ��ֹ����Ҫ���±�+1
	while (left1 <= right1 && left2 <= right2){
		if (vec[left1] <= vec[left2]){
			tmp[k++] = vec[left1++];
		}else{
			tmp[k++] = vec[left2++];
		}
	}
	while (left1 <= right1){
		tmp[k++] = vec[left1++];
	}
	while (left2 <= right2){
		tmp[k++] = vec[left2++];
	}
	for (int k = l; k <= r; k++){
		vec[k] = tmp[k];
	}
}
//������
//ά���ѵ�����С�˶ѣ�����2�����ڵ�ĸ��ڵ㣬����3����ֹ�±�+1
void heapify(vector<int> &vec, int i, int n) {
	if (i >= n) return;
	int last_node = i;
	int left_node = 2 * i + 1;
	int right_node = 2 * i + 2;
	if (left_node < n && vec[left_node] > vec[last_node]) last_node = left_node;
	if (right_node < n && vec[right_node] > vec[last_node]) last_node = right_node;
	if (last_node != i) {
		swap(vec[last_node], vec[i]);
		heapify(vec, last_node, n);
	}
}
// ����2�����鳤��
void Heap_Sort(vector<int> &vec, int n) {
	//����
	for (int i = (n-1-1) / 2; i >= 0; i--) {//���ڵ��±꣺(n-1-1)/2
		heapify(vec, i, n);
	}
	//ά���ѵ����ʣ��ú󲻶ϰ���Ѷ�
	for (int i = n - 1; i >= 0; i--) {
		swap(vec[0], vec[i]);
		heapify(vec, 0, i);
	}
}
//�������򣬷ǱȽ�����
void Count_Sort(vector<int>& vec) {
	int max = *max_element(vec.begin(), vec.end());
	vector<int> tmp1(max + 1, 0);
	for (int i = 0; i < vec.size(); i++) {
		tmp1[vec[i]]++;
	}
	
	vector<int> tmp2(max + 1, 0);
	int sum = 0;
	for (int i = 0; i < tmp2.size(); i++) {
		tmp2[i] = sum + tmp1[i];
		sum = tmp2[i];
	}
	vector<int> tmp3(vec.size(), 0);
	for (int i = 0; i < vec.size(); i++) {
		int pos = tmp2[vec[i]];
		tmp3[pos - 1] = vec[i];
		tmp2[vec[i]]--;
	}
	swap(tmp3, vec);
}
//�������򣬷ǱȽ�����
void Redix_Sort(vector<int>& vec) {
	int max = *max_element(vec.begin(), vec.end());
	//ȷ��λ��
	int n = 0;
	while (max) { max = max / 10; n++;}
	//ȷ������
	vector<queue<int>> vec_que(10, queue<int>());

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < vec.size(); i++) {
			int tmp = pow(10, k);
			int pos = (vec[i]/tmp) % 10;
			vec_que[pos].push(vec[i]);
		}
		vec.clear();
		for (int i = 0; i < vec_que.size(); i++) {
			while (!vec_que[i].empty()) {
				int tmp = vec_que[i].front();
				vec.push_back(tmp);
				vec_que[i].pop();
			}
		}
	}
}

/**** ���ߺ��� *****/
void printval(int val) {
	printf("%d ", val);
}

void create_data(vector<int> &vec) {// ���ɲ�������
	// rand() %(n-m+1)+m ->[m,n]��Χֵ
	srand(time(0));
	//rand()�᷵��һ����Χ��0��RAND_MAX��������32767��֮���α�������������
	for (int i = 0; i < 20; i++) {
		int tmp = rand() % (100 - 0 + 1) + 0;
		vec.emplace_back(tmp);
	}
}

long Choose_Sort(vector<int>& vec, Sorts index) {
	auto start = chrono::steady_clock::now(); // ��ʱ�� us����

	switch (index) {
	case Sorts::Bobble: {Bobble_Sort(vec); break; }
	case Sorts::Quick: {Quick_Sort(vec, 0, vec.size() - 1); break; }
	case Sorts::Insert: {Insert_Sort(vec); break; }
	case Sorts::Shell: {Shell_Sort(vec, 3); break; }
	case Sorts::Choose: {Choose_Sort(vec); break; }
	case Sorts::Merge: {vector<int> tmp(vec); Merge_Sort(vec, tmp, 0, vec.size() - 1);; break; }
	case Sorts::Heap: {Heap_Sort(vec, vec.size()); break; }
	case Sorts::Count: {Count_Sort(vec); break; }
	case Sorts::Redix: {Redix_Sort(vec); break; }
	default:
		break;
	}

	auto end = chrono::steady_clock::now();
	auto last = chrono::duration_cast<chrono::microseconds>(end - start);
	long t = last.count();// ������long long

	return t;
}

int main() {

	vector<int> vec;
	create_data(vec);
	printf("����ǰ��");
	for_each(vec.begin(), vec.end(), printval);
	printf("\n");
	printf("�����");
	// ����
	long t = Choose_Sort(vec, Sorts::Redix);
	for_each(vec.begin(), vec.end(), printval);
	printf("\n ��ʱ��%d us", t);

	return 0;
}