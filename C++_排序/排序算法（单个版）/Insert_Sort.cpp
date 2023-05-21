/*
 * ����������ʵ�� �������� 
 * ƽ��ʱ�临�Ӷ�Ϊ��n^2  � n^2 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Insert_Sort(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		for(int j=i-1; j>=0; j--){
			if(vec[j+1] >= vec[j]) break;
			if(vec[j+1] < vec[j]) swap(vec[j+1], vec[j]);
		}
	}
}

void printval(int val){
	printf("%d ", val);
}

int main(){
	vector<int> test_vec = {2,4,5,1,6,2,7,8,10};
	
	Insert_Sort(test_vec);
	
	for_each(test_vec.begin(), test_vec.end(), printval); 
	
	return 0;
}
