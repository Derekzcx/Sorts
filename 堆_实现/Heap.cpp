/*
*  ����������ʵ�ֶѣ��������������Ķ����� 
*	�֣��󶥶� ��С���� 
*   �±�Ϊi��:
	���ڵ��±꣺(i-1)/2
 	��ڵ��±꣺2*i+1
	�ҽڵ��±꣺2*i+2 
*/
#include<iostream>
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


 

int main(){
	
	
	return 0;
}
