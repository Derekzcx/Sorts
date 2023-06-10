/*
	本程序用于实现9大排序
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<random> // rand(), srand();
#include<ctime>
#include <chrono> // C++ 的微秒级别库
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

/***** 排序算法 *****/
// 1 冒泡排序,时间复杂度 n^2
void Bobble_Sort(vector<int> &vec) {
	for (int i = 0; i < vec.size()-1; i++) {
		for (int j = i+1; j < vec.size(); j++) {
			if (vec[j] < vec[i]) swap(vec[j], vec[i]);
		}
	}
}
// 2 快排, 时间复杂度  nlogn
// 参数1：待排序序列；参数2：序列最左端下标；参数3：序列最右端下标
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
	Quick_Sort(vec, left, l); //注意是以基准点位置为分区
	Quick_Sort(vec, l + 1, right);
}
// 插入排序, 时间复杂度 n^2
void Insert_Sort(vector<int>& vec) {
	for (int i = 1; i < vec.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (vec[j + 1] < vec[j]) swap(vec[j + 1], vec[j]);
			else break;
		}
	}
}
// 希尔排序， 时间复杂度 为 n^1.3
// 参数2：为分段排序的分段
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
// 选择排序, 时间复杂度为 n^2, 选择最小元素
void Choose_Sort(vector<int>& vec) {
	for (int i = 0; i < vec.size()-1; i++) {
		int min = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[min]) min = j;
		}
		swap(vec[min], vec[i]);
	}
}
// 归并排序，时间复杂度为 nlogn
// 参数2：零时数组 参数3：左端下标; 参数4：右端下标
void Merge_Sort(vector<int> &vec, vector<int> &tmp, int l, int r) {
	if (l >= r) return;
	int left1 = l;
	int right1 = (l + r) / 2;
	int left2 = right1 + 1;
	int right2 = r;
	Merge_Sort(vec, tmp, left1, right1);
	Merge_Sort(vec, tmp, left2, right2);

	int k = l;// 还是需要下标为截止，不要用下标+1
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
//堆排序
//维护堆的性质小端堆：参数2：三节点的根节点，参数3：截止下标+1
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
// 参数2：数组长度
void Heap_Sort(vector<int> &vec, int n) {
	//建堆
	for (int i = (n-1-1) / 2; i >= 0; i--) {//父节点下标：(n-1-1)/2
		heapify(vec, i, n);
	}
	//维护堆的性质，让后不断剥离堆顶
	for (int i = n - 1; i >= 0; i--) {
		swap(vec[0], vec[i]);
		heapify(vec, 0, i);
	}
}
//计数排序，非比较排序
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
//基数排序，非比较排序
void Redix_Sort(vector<int>& vec) {
	int max = *max_element(vec.begin(), vec.end());
	//确定位数
	int n = 0;
	while (max) { max = max / 10; n++;}
	//确定队列
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

/**** 工具函数 *****/
void printval(int val) {
	printf("%d ", val);
}

void create_data(vector<int> &vec) {// 生成测试数据
	// rand() %(n-m+1)+m ->[m,n]范围值
	srand(time(0));
	//rand()会返回一个范围在0到RAND_MAX（至少是32767）之间的伪随机数（整数）
	for (int i = 0; i < 20; i++) {
		int tmp = rand() % (100 - 0 + 1) + 0;
		vec.emplace_back(tmp);
	}
}

long Choose_Sort(vector<int>& vec, Sorts index) {
	auto start = chrono::steady_clock::now(); // 计时器 us级别

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
	long t = last.count();// 返回是long long

	return t;
}

int main() {

	vector<int> vec;
	create_data(vec);
	printf("排序前：");
	for_each(vec.begin(), vec.end(), printval);
	printf("\n");
	printf("排序后：");
	// 排序
	long t = Choose_Sort(vec, Sorts::Redix);
	for_each(vec.begin(), vec.end(), printval);
	printf("\n 耗时：%d us", t);

	return 0;
}