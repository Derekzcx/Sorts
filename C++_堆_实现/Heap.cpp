/*
*  本程序用于实现堆，即采用数组管理的二叉树 
*	分：大顶堆 、小顶推 
*   下标为i的:
	父节点下标：(i-1)/2
 	左节点下标：2*i+1
	右节点下标：2*i+2 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 插入节点，hole 表示新元素所在位置 ,以维护大顶堆为例 
void push_heap(vector<int> &arr, int hole){
	int val = arr[hole]; // 得到新元素的值 
	int parent = (hole - 1) / 2; // 得到父节点下标 
	while(hole > 0 && arr[parent] < val){ // 去找合适val的位置 
		arr[hole] = arr[parent];
		hole = parent;
		parent = (hole - 1) / 2;
	}
	arr[hole] = val;
} 

// 维护堆的性质,(以大顶堆为例) - 递归 
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

// 建堆 _ _ arr为待建堆的数组，n为数组大小 
void Create_Heap(vector<int> &arr, int n){
	for(int i=(n-1-1)/2; i>=0; i--){
		heapify(arr, i, n);
	}
} 

// 删除堆顶元素 
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
	//建堆测试
	Create_Heap(arr, arr.size());
	for_each(arr.begin(), arr.end(), printval); 
	
	cout << endl;
	//插入节点测试 - 方法1 - 迭代方法 
	arr.push_back(20);
	push_heap(arr,arr.size()-1);
	for_each(arr.begin(), arr.end(), printval); 
	
	cout << endl;
	// 插入节点测试 - 方法2 - 递归方法（再创建一次堆） 
	Create_Heap(arr, arr.size());
	for_each(arr.begin(), arr.end(), printval);
	
	cout << endl;
	// 删除堆顶 
	Delete_Top(arr);
	for_each(arr.begin(), arr.end(), printval);
	
	return 0;
}
