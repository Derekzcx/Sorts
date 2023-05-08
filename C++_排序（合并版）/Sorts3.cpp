#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib> 
#include<algorithm>

using namespace std;

/******************** 算法函数 ************************/
void Bubble_Sort(vector<int> &vec){
	for(int i=0; i<vec.size()-1; i++){
		for(int j = i+1; j<vec.size(); j++){
			if(vec[i] > vec[j]) swap(vec[i],vec[j]);
		}
	}
} 

/******************** 工具函数 ************************/
void create_testval(vector<int> &vec){
	unsigned int seed = time(0); // 以当前时间为种子
	srand(seed); 
	for(int i=1; i<=3; i++){
		int k = rand() % 3 + 1;
		int max = pow(10,k);
		int min = 0;
		for(int j = 0; j< 5; j++){
			int num = rand() % (max - min + 1) + min;
			vec.emplace_back(num);
		}
	}  
}
void printval(int &val){
	printf("%d ",val);
}

int main(){
	vector<int> vec;
	create_testval(vec);
	printf("before: ");
	for_each(vec.begin(), vec.end(),printval);
	printf("\n");
	printf("alfter: ");
	Bubble_Sort(vec);
	for_each(vec.begin(), vec.end(),printval);
	return 0;
}
