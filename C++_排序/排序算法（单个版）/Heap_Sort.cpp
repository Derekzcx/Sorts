/*
 * 本程序用于堆排序 
 * 平均时间复杂度为 logn 
*/
/**
 * 从大到小为，大顶堆，其实用到的就是二叉树的概念，父节点大于子节点 。 
 * 从小到大 为 小顶堆  ，父节点小于子节点 
 
 * 采用 数组保存二叉树时，需要知道的概念是 
 * 下标为 i 的节点的父节点 下标为 （i-1）/2 (取整) 
 * 下标为 i 的节点的左孩子节点 下标为 i*2 + 1
 * 下标为 i 的节点的右孩子节点 下标为 i*2 + 2  
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	堆排序的过程是：
	（1）定义一个递归函数用于维护堆的性质（大顶堆或小顶堆）
	（2）另外一个函数：建堆（从尾部n-1的父节点开始建）；
		先维护堆的性质，再把堆根节点值与数组末尾进行交换，并与前面堆断开；
		 继续维护断开末尾元素后的堆，继续将新的根节点与新末尾进行交换，并前面堆断开； 
		 依次类推 
*/


// n 表示 元素个数 
void Heapify(vector<int> &vec,int n, int i){ //将当前堆中最大的递归的交换的根节点处（下标为0） 
	//if(i > n) return;
	int root = i;
	int left = i*2+1; //左孩子下标 
	int right = i*2+2; // 右孩子下标
	
	if(left < n && vec[root] < vec[left]){
		root = left;
	}
	if(right < n && vec[root] < vec[right]){
		root = right;
	}
	if(root != i){
		swap(vec[root], vec[i]);
		Heapify(vec, n, root);	
	}
}
void Heap_Sort(vector<int> &vec, int n){
	//建堆；要从右边开始找对应的父节点，(i-1)/2 i=n-1 开始 
	for(int i = n/2 -1; i>=0; i--){  // n/2-1 : ((n-1)-1)/2  
		Heapify(vec, n, i);
	} 
	// 排序
	for(int i = n-1; i > 0; i--){
		swap(vec[i], vec[0]); //将根节点值与尾部下标的元素交换
		Heapify(vec, i, 0); // 维护大顶堆的性质 
	} 
}

void printval(int val){
	printf("%d ", val);
}
int main(){
	vector<int> test_vec = {2,4,5,1,6,2,7,8,10,11,0,2,11,3,20,1,8,9};
	
    Heap_Sort(test_vec, test_vec.size());
	
	for_each(test_vec.begin(), test_vec.end(), printval);
	
	return 0;
}
