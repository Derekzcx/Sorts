/*
*  ���������� �������� ��ʵ�� 
*	���ڷǱȽ������� 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Count_Sort(vector<int> &vec){
	if(vec.size() <= 2) return;
	
	//1 �ҵ������С��Ԫ��
	//int max = *max_element(vec.begin(), vec.end());
	//int min = *min_element(vec.begin(), vec.end());
	 // or
	int max = INT_MIN;
	int min = INT_MAX;
	for(int i=0; i<vec.size(); i++){
		if(max < vec[i]) max = vec[i];
		if(min > vec[i]) min = vec[i];
	} 
	// ����һ�������ռ��±��ӦԪ��
	vector<int> count_vec(max+1, 0);
	vector<int> sum_vec(max+1, 0);

	// ���� 
	for(int i=0; i<vec.size(); i++){
		count_vec[vec[i]]++; 
	}
	
	// �ۼƼ����õ���Ԫ�ص�λ�ã�Ԫ��ֵ�����±꣩
	int sum = 0; 
    for(int i=min; i<sum_vec.size(); i++){
    	sum_vec[i] = sum + count_vec[i];
		sum = sum_vec[i]; 
	}

	//����sum_vec�����µ�����
	 vector<int> new_vec(vec.size(), 0);
	 for(int i=0; i< vec.size(); i++){
		int position = sum_vec[vec[i]];
		new_vec[position-1] = vec[i]; // �±��0��ʼ�� 
		sum_vec[vec[i]]--; //�ۼƼ�������ֵһ�Σ���һ�� 
	 }
	 vec = new_vec;
}

void printval(int val){
	printf("%d ", val);
}

int main(){
	vector<int> vec = {2,4,5,1,6,2,7,8,10,11,0,2,11,3,20,1,8,9};
 
    for_each(vec.begin(), vec.end(), printval);
    
    Count_Sort(vec);
    
    printf("\n***\n");
    
	for_each(vec.begin(), vec.end(), printval);
	
	return 0;
}
