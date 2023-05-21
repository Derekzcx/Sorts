/*
*	����������ʵ�� ��������  
*	�����������ڷǱȽ����� 
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

/*
	��������Ĺ����ǣ��������ά���飬һά�±�Ϊ0-9 
*/ 

void printval(int val){
	printf("%d ", val);
}


void Redix_Sort(vector<int> &vec){
	queue<int> que;
	vector<queue<int>> tmp(10, que); // һά�±��ʾ0-9����ά�����ݴ�Ԫ�أ��м��Ƚ��ȳ�
	
	// ���ҵ����Ԫ�أ�ȷ�����Ԫ���Ǽ�λ��
	int max = *max_element(vec.begin(), vec.end());
	int num = 0;
	while(max != 0){
		max = max/10;
		num++;
	}
	// �Ӹ�λ��ʼ�����Ӧ�±��tmp�� 
 	for(int i=0; i<num; i++){
		for(int j=0; j<vec.size(); j++){
			int m = vec[j]/pow(10, i); //���� ���� λ���ȸ�λ��ʮλ����λ������ 
			int n = m%10;
			tmp[n].push(vec[j]);
		}
		vec.clear(); // ����ɾ����������Ž�ȥ, tmp ����һά�����ң���ά�������� 
		for(int j=0; j<tmp.size(); j++){ 
			while(!tmp[j].empty()){
				vec.emplace_back(tmp[j].front());
				tmp[j].pop();
			}
		}
	} 
} 

int main(){
	vector<int> vec = {12, 11, 0, 11, 1, 2, 8, 19, 29, 30, 15, 35, 45, 100, 101, 4009};
	
	for_each(vec.begin(), vec.end(), printval);	
	
	Redix_Sort(vec);
	
	printf("�����\n");
	
	for_each(vec.begin(), vec.end(), printval);	
	
	return 0;
}
