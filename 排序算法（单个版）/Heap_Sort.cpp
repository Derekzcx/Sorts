/*
 * ���������ڶ����� 
 * ƽ��ʱ�临�Ӷ�Ϊ logn 
*/
/**
 * �Ӵ�СΪ���󶥶ѣ���ʵ�õ��ľ��Ƕ������ĸ�����ڵ�����ӽڵ� �� 
 * ��С���� Ϊ С����  �����ڵ�С���ӽڵ� 
 
 * ���� ���鱣�������ʱ����Ҫ֪���ĸ����� 
 * �±�Ϊ i �Ľڵ�ĸ��ڵ� �±�Ϊ ��i-1��/2 (ȡ��) 
 * �±�Ϊ i �Ľڵ�����ӽڵ� �±�Ϊ i*2 + 1
 * �±�Ϊ i �Ľڵ���Һ��ӽڵ� �±�Ϊ i*2 + 2  
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	������Ĺ����ǣ�
	��1������һ���ݹ麯������ά���ѵ����ʣ��󶥶ѻ�С���ѣ�
	��2������һ�����������ѣ���β��n-1�ĸ��ڵ㿪ʼ������
		��ά���ѵ����ʣ��ٰѶѸ��ڵ�ֵ������ĩβ���н���������ǰ��ѶϿ���
		 ����ά���Ͽ�ĩβԪ�غ�Ķѣ��������µĸ��ڵ�����ĩβ���н�������ǰ��ѶϿ��� 
		 �������� 
*/


// n ��ʾ Ԫ�ظ��� 
void Heapify(vector<int> &vec,int n, int i){ //����ǰ�������ĵݹ�Ľ����ĸ��ڵ㴦���±�Ϊ0�� 
	//if(i > n) return;
	int root = i;
	int left = i*2+1; //�����±� 
	int right = i*2+2; // �Һ����±�
	
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
	//���ѣ�Ҫ���ұ߿�ʼ�Ҷ�Ӧ�ĸ��ڵ㣬(i-1)/2 i=n-1 ��ʼ 
	for(int i = n/2 -1; i>=0; i--){  // n/2-1 : ((n-1)-1)/2  
		Heapify(vec, n, i);
	} 
	// ����
	for(int i = n-1; i > 0; i--){
		swap(vec[i], vec[0]); //�����ڵ�ֵ��β���±��Ԫ�ؽ���
		Heapify(vec, i, 0); // ά���󶥶ѵ����� 
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
