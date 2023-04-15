#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

//ð������ ƽ��ʱ�临�Ӷ�Ϊ n^2
void Bubble_Sort(vector<int> &vec){
	for(int i =0; i<vec.size()-1; i++){
		for(int j=i+1; j<vec.size(); j++){
			if(vec[j] < vec[i]) swap(vec[j], vec[i]);
		}
	}
} 
// �������� ��ƽ��ʱ�临�Ӷ�Ϊ n^2
void Insert_Sort(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		for(int j=i-1; j>=0; j--){
			if(vec[j+1]<vec[j]) swap(vec[j], vec[j+1]);
			else break;
		}
	}
} 

// ϣ������ƽ��ʱ�临�Ӷ�Ϊ n^1.3, ����2 ��ʾ��ʼ��� 
void Shell_Sort(vector<int> &vec, int n){
	while(n != 0){
		for(int k =0 ; k<n ; k++){
			for(int i=k+n; i<vec.size(); i+=n){
				for(int j=i-n; j>=0; j-=n){
					if(vec[j+n] < vec[j]) swap(vec[j+n], vec[j]);
					else break;
				}
			}
		}
		n = n/2;
	}
} 

// ����, ƽ��ʱ�临�Ӷ�Ϊ nlogn
void Quick_Sort(vector<int> &vec, int l, int r){
	if(l>=r) return;
	int base_val = vec[l];
	int left = l;
	int right = r;
	bool flag = false;
	while(l!=r){
		if(flag == false){ // ���ұ� 
			if(vec[r] < base_val){
				vec[l] = vec[r];
				l++;
				flag = true;
			}else{
				r--;
			}
		}else{ // ����� 
			if(vec[l] > base_val){
				vec[r] = vec[l];
				r--;
				flag = false;
			}else{
				l++;
			}
		}
	}
	vec[l] = base_val;
	Quick_Sort(vec, left, l);
	Quick_Sort(vec, l+1, right);
} 

// ѡ������ , ƽ��ʱ�临�Ӷ�Ϊ n^2
void Insertion_Sort(vector<int> &vec){
	//ѡ����Сֵһֱ�ŵ�ȫ��
	for(int i=0; i<vec.size()-1; i++){
		int min = i;
		for(int j=i+1; j<vec.size(); j++){
			if(vec[j] < vec[min]) {min = j;}
		}
		swap(vec[i], vec[min]);	
	} 
} 

// �鲢����, ƽ��ʱ�临�Ӷ�Ϊ nlogn
void Merga_Sort(vector<int> &vec, vector<int> &tmp, int l, int r){
	// ���� 
	if(l >= r) return;
	// ��ʽ�ϵķ���
	int left1 = l;
	int right1 = (l+r)/2;
	int left2 = right1 + 1;
	int right2 = r;
	Merga_Sort(vec,tmp,left1, right1);
	Merga_Sort(vec, tmp, left2, right2);
	
	// �ϲ�
	int k = l;
	while(left1 <= right1 && left2 <= right2){
		if(vec[left1] <= vec[left2]){
			tmp[k] = vec[left1];
			left1++;
			k++;
		}else{
			tmp[k] = vec[left2];
			left2++;
			k++;
		}
	} 
	while(left1 <= right1){
		tmp[k] = vec[left1];
		left1++;
		k++;
	}
	while(left2 <=right2){
		tmp[k] = vec[left2];
		left2++;
		k++;
	}
	for(int k=l; k<=r; k++){
		vec[k] = tmp[k];
	}
} 


// ������ƽ��ʱ�临�Ӷ�Ϊ nlogn
void heapfiy(vector<int> &vec, int i, int end){
	if(i >= end) return;
	int last_node = i;
	int left_son = 2*i+1;
	int right_son = 2*i+2;
	if(left_son < end && vec[left_son] > vec[last_node]) last_node = left_son;
	if(right_son < end && vec[right_son] > vec[last_node]) last_node = right_son;
	if(last_node != i){
		swap(vec[last_node] , vec[i]);
		heapfiy(vec, last_node, end);
	}
} 
void Heap_Sort(vector<int> &vec, int n){
	// ��һ�ν��� �� 
	for(int i = (n-1-1)/2; i>=0; i--){
		heapfiy(vec, i, n);
	}
	// ά���ѵ�����
	for(int i=n-1; i>=0; i--){
		swap(vec[0], vec[i]);
		heapfiy(vec, 0, i);
	} 
}
 
// ��������
void Count_Sort(vector<int> &vec, vector<int> &tmp_out){
	//1 �ҵ���������ȷ����������
	int max = *max_element(vec.begin(), vec.end());
	vector<int> tmp1(max+1, 0); // ������¼Ԫ�صĸ��� 
	vector<int> tmp2(max+1, 0); // ������¼Ԫ�ص�λ��
	// 2 ��¼Ԫ�صĸ��� 
	for(int i=0; i<vec.size(); i++){
		tmp1[vec[i]]++;
	} 
	// 3 ͨ���ۼ�ȷ��Ԫ�ص�λ�� 
	int sum=0;
	for(int i=0; i<tmp1.size(); i++){
		sum +=tmp1[i];
		tmp2[i]=sum;
	}
	// 4 ����λ�õõ����������� 
	for(int i=0; i<vec.size(); i++){
		int pos = tmp2[vec[i]];
		tmp_out[pos-1] = vec[i];
		tmp2[vec[i]]--;
	}
} 

// ��������
void Redix_Sort(vector<int> &vec){
	// 1 �ҵ�����Ԫ��
	int n = *max_element(vec.begin(), vec.end());
	// 2 ȷ�����Ԫ�ص�λ�� 
	int k = 0;
	while(n!=0){
		n = n/10;
		k++;
	}
	// ȷ����Ҫ����k��װȡ, װȡ��������һ������10�����е�����
	queue<int> que;
	vector<queue<int>> vec_que(10, que);
	
	for(int i=0; i<k; i++){
		//��װ
		for(int j = 0; j< vec.size(); j++){
			int tmp1 = pow(10, i);
			int tmp2 = (vec[j]/tmp1)%10;
			vec_que[tmp2].push(vec[j]);
		}
		vec.clear();
		//��ȡ 
		for(int j=0; j<10; j++){
			while(!vec_que[j].empty()){
				vec.emplace_back(vec_que[j].front());
				vec_que[j].pop();
			}
		}
	} 
	 
} 


//������ӡ
void printval(int val){
	printf("%d ", val);
} 
int main(){
	vector<int> vec{1, 12, 31, 11, 0, 2, 26, 240, 241, 3009, 11, 2, 11, 0, 12, 9, 111, 999};
	const char* str1 = "before sort:";
	const char* str2 = "after sort:" ;
	printf("%s \n", str1);
	for_each(vec.begin(), vec.end(), printval);
	printf("\n");
	printf("%s \n", str2);
	
	// ð���������
//	Bubble_Sort(vec);
//	for_each(vec.begin(), vec.end(), printval);

	// �����������
//	Insert_Sort(vec);
//	for_each(vec.begin(), vec.end(), printval);
	
	// ϣ������ 
//	Shell_Sort(vec, 4);
//	for_each(vec.begin(), vec.end(), printval);
	
	// ���� 
//	Quick_Sort(vec, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval);

    // ѡ������ 
//	Insertion_Sort(vec);
//    for_each(vec.begin(), vec.end(), printval);

	// �鲢���� 
//	vector<int> tmp(vec.size(), 0);
//	Merga_Sort(vec, tmp, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval);

	// ������ 
//	Heap_Sort(vec, vec.size());
//	for_each(vec.begin(), vec.end(), printval);

//  �������� 
//	vector<int> result(vec.begin(),vec.end());
//	Count_Sort(vec, result);
//	for_each(result.begin(), result.end(), printval);
	
	// ��������
	Redix_Sort(vec);
	for_each(vec.begin(), vec.end(), printval);
	
	return 0;
}
