/*
*	本程序用于实现 基数排序  
*	基数排序属于非比较排序 
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

/*
	基数排序的过程是，定义组二维数组，一维下标为0-9 
*/ 

void printval(int val){
	printf("%d ", val);
}


void Redix_Sort(vector<int> &vec){
	queue<int> que;
	vector<queue<int>> tmp(10, que); // 一维下标表示0-9，二维用于暂存元素，切记先进先出
	
	// 先找到最大元素，确定最大元素是几位数
	int max = *max_element(vec.begin(), vec.end());
	int num = 0;
	while(max != 0){
		max = max/10;
		num++;
	}
	// 从个位开始存入对应下标的tmp中 
 	for(int i=0; i<num; i++){
		for(int j=0; j<vec.size(); j++){
			int m = vec[j]/pow(10, i); //更新 参照 位，先个位、十位、百位。。。 
			int n = m%10;
			tmp[n].push(vec[j]);
		}
		vec.clear(); // 清理干净后，再重新排进去, tmp 必须一维从左到右，二维从上往下 
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
	
	printf("排序后：\n");
	
	for_each(vec.begin(), vec.end(), printval);	
	
	return 0;
}
