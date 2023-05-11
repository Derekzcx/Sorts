/*
* 01背包问题解题 
* 		0 	1 				2 	3 	4 	5 	6
（0,0） 0	0				0	0	0	0	0
（1,2） 0	0+[1-1][1-1]+2 ...
（2,3）	0	...
（3,4）	0
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define back_size 6	// 背包的最大容量  

int Back_01(const vector<pair<int, int>> &good){
	int num = good.size();
	vector<int> tmp(back_size+1, 0);
	vector<vector<int>> dp(num, tmp);
	//1 确保 dp[0][j] 都为0， dp[i][0] 为 0，以上已做到
	int sum = 0;
	for(int i=1; i<num; i++){
		for(int j=1; j<=back_size; j++){
			if(good[i].first > j ) {dp[i][j] = dp[i-1][j]; continue;} // 要求dp表的每个单位对应的good的重量大于对应的背包容量 
			dp[i][j] = dp[i-1][j] + dp[i-1][j-good[i].first] + good[i].second; // 更新dp 
		}
	}
	// 
	printf("\n");
	printf("****************** dp table *********************\n");
	
	for(int i=0; i<num; i++){
		printf("\n");
		for(int j=1; j<=back_size; j++){
			printf("%d ", dp[i][j]);
		}
	}
	
	return dp[num-1][back_size];
}

void init_good(vector<pair<int, int>> &good){
	int num  = 3;
	for(int i=0; i< num+1; i++){
		good.push_back(make_pair(i+1, i+2));
	}
	good[0] = make_pair(0, 0);
}

int main(){
	vector<pair<int, int>> good; // 物品的重量和价值 
	init_good(good);
	printf("information of goods(weight, value):\n");
	for(int i =0; i<good.size(); i++){
		printf("[%d , %d] ", good[i].first, good[i].second);
	}
	int result = Back_01(good);
	printf("\n\n");
	printf("max value : %d",result);
	return 0;
}
