/*
*  ����������ʵ�� ֱ��ѡ������ 
*  ƽ��ʱ�临�Ӷ�Ϊ��n^2 ��������Ҳ��n^2 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

const int max = INT_MIN;
const int min = INT_MAX;

void Insertion_Sort(vector<int> &vec){
	// ֱ��ѡ�����򣬾���ѡ����С�����Ԫ�أ�����β���ٶ�ʣ�µ�Ԫ�ؼ��������Ĳ���	
	int l = 0;
	int r = vec.size()-1;
	int max_pos = l;
	int min_pos = l;
	while(l<=r){
		for(int i=l; i <= r; i++){
			if(vec[max_pos] < vec[i]){
				max_pos = i;
			}
			if(vec[min_pos] > vec[i]){
				min_pos = i;
			}	
		}
		swap(vec[l], vec[min_pos]);
		swap(vec[r], vec[max_pos]);
		l++;
		r--;
	}
}

void printval(int val){
	printf("%d ", val);
}

int main(){
	vector<int> test_vec = {2,4,5,1,6,2,7,8,10,11,0,2,11,3,20,1,8,9};
	
	Insertion_Sort(test_vec);
	
	for_each(test_vec.begin(), test_vec.end(), printval);
	
	return 0;
} 
