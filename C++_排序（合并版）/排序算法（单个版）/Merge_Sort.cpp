/*
* ���������� ��·�鲢���� Merge Sort 
* ��·�鲢�����ʱ�临�Ӷ�Ϊ  nlogn 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 1 �ݹ�ķ�����(l��r��ʽ�ϵķ���)��һֱ������ֻ��һ��
void Merge_Sort(vector<int> &vec, vector<int> tmp, int l, int r){
	if(l>=r) return;
	int mid = (l+r)/2;
	int left1 = l;
	int right1 = mid;
	int left2 = mid+1;
	int right2 = r;
	//���� 
	Merge_Sort(vec, tmp,  left1, right1);
	Merge_Sort(vec, tmp, left2, right2);
	//�ϲ�
	int k = l;
	while(left1 <= right1 && left2 <= right2){
		if(vec[left1] <= vec[left2]){
			tmp[k] = vec[left1];
			left1++;
		}else{
			tmp[k] = vec[left2];
			left2++;
		}
		k++;
	} 
	while(left1 <= right1){
		tmp[k] = vec[left1];
		left1++;
		k++;
	}
	while(left2 <= right2){
		tmp[k] = vec[left2];
		left2++;
		k++;
	}
	for(int k = l; k<=r; k++){
		vec[k] = tmp[k];
	}
}

void printval(int val){
	printf("%d ", val);
}


int main(){
    vector<int> vec = {2,4,5,1,6,2,7,8,10,11,0,2,11,3,20,1,8,9};
 
    for_each(vec.begin(), vec.end(), printval);

	vector<int> tmp(vec.begin(), vec.end());
     
    printf("\n");
	
	Merge_Sort(vec, tmp, 0, vec.size()-1);
	
	for_each(vec.begin(), vec.end(), printval);
	
	return 0;
}
