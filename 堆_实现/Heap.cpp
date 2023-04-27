/*
*  本程序用于实现堆，即采用数组管理的二叉树 
*	分：大顶堆 、小顶推 
*   下标为i的:
	父节点下标：(i-1)/2
 	左节点下标：2*i+1
	右节点下标：2*i+2 
*/
#include<iostream>
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


 

int main(){
	
	
	return 0;
}
