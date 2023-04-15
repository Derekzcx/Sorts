/*
 * 本程序用于实现 希尔排序 
 * 平均时间复杂度为 n^1.3 ，最坏 n^2 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//希尔排序，默认从小到大排 
void Shell_Sort(vector<int> &vec , int n){
	//这个设置间隔为4，2，1 
	//int n=4; // 每轮排序后更新 n = n/2
	if(n > vec.size()-1) return;
	while(n != 0){
		// 间隔n ，就执行多少次插入排序 
		for(int k=0; k<n; k++){
			//一轮插入排序 
			for(int i=n; i < vec.size(); i = i+n){
				for(int j=i-n; j >= 0; j=j-n){
					if(vec[j+n] < vec[j]) swap(vec[j+n],vec[j]);
				}
			} 
		}
		n = n/2;
	}

}

void printval(int val){
	printf("%d ", val);
}

int main(){
	vector<int> test_vec = {2,4,5,1,6,2,7,8,10,11,0,2,11,3,20,1,8,9};
	
	Shell_Sort(test_vec,4);
	
	for_each(test_vec.begin(), test_vec.end(), printval);
	
	return 0;
}

