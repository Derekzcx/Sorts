/*
*  ����������ʵ�ֶѣ��������������Ķ����� 
*	�֣��󶥶� ��С���� 
*   �±�Ϊi��:
	���ڵ��±꣺(i-1)/2
 	��ڵ��±꣺2*i+1
	�ҽڵ��±꣺2*i+2 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ����ڵ㣬hole ��ʾ��Ԫ������λ�� ,��ά���󶥶�Ϊ�� 
void push_heap(vector<int> &arr, int hole){
	int val = arr[hole]; // �õ���Ԫ�ص�ֵ 
	int parent = (hole - 1) / 2; // �õ����ڵ��±� 
	while(hole > 0 && arr[parent] < val){ // ȥ�Һ���val��λ�� 
		arr[hole] = arr[parent];
		hole = parent;
		parent = (hole - 1) / 2;
	}
	arr[hole] = val;
} 

// ά���ѵ�����,(�Դ󶥶�Ϊ��) - �ݹ� 
void heapify(vector<int> &arr, int i, int n){
	if(i>=n) return;
	int last_root = i;
	int left_son = 2*i+1;
	int right_son = 2*i+2;
	if(left_son < n && arr[left_son] > arr[last_root]) last_root = left_son;
	if(right_son < n && arr[right_son] > arr[last_root]) last_root = right_son;
	if(last_root != i){
		swap(arr[last_root], arr[i]);
		heapify(arr, last_root, n);
	}			
} 

// ���� _ _ arrΪ�����ѵ����飬nΪ�����С 
void Create_Heap(vector<int> &arr, int n){
	for(int i=(n-1-1)/2; i>=0; i--){
		heapify(arr, i, n);
	}
} 

// ɾ���Ѷ�Ԫ�� 
void Delete_Top(vector<int> &arr){
	swap(arr[0], arr[arr.size()-1]);
	heapify(arr, 0, arr.size()-1);
	arr.pop_back();
} 

void printval(int val){
	printf("%d ", val);
}
 
int main(){
	vector<int> arr{3,2,5,1,0,2,10,9,11};
	//���Ѳ���
	Create_Heap(arr, arr.size());
	for_each(arr.begin(), arr.end(), printval); 
	
	cout << endl;
	//����ڵ���� - ����1 - �������� 
	arr.push_back(20);
	push_heap(arr,arr.size()-1);
	for_each(arr.begin(), arr.end(), printval); 
	
	cout << endl;
	// ����ڵ���� - ����2 - �ݹ鷽�����ٴ���һ�ζѣ� 
	Create_Heap(arr, arr.size());
	for_each(arr.begin(), arr.end(), printval);
	
	cout << endl;
	// ɾ���Ѷ� 
	Delete_Top(arr);
	for_each(arr.begin(), arr.end(), printval);
	
	return 0;
}
