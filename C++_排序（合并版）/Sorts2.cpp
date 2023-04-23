#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib> // rand() 和 srand() 需要
#include<ctime>  // 使用 time 需要 

using namespace std;

// 冒泡排序 ，平均时间复杂度为 n^2 
void Buble_Sort(vector<int> &vec);

// 快排，平均时间复杂度为 nlogn : 形参 l，r分别表示头尾下标 
void Quick_Sort(vector<int> &vec, int l, int r);

// 插入排序，平均时间复杂度为 n^2
void Insert_Sort(vector<int> &vec); 

// 希尔排序，平均时间复杂度为 n^1.3: 形参 n 表示间隔数 
void Shell_Sort(vector<int> &vec, int n); 
 
// 选择排序, 平均时间复杂度为 n^2 
void Insertion_Sort(vector<int> &vec);

// 打印测试 
void printval(int &val);

// 产生随机数用于排序
void Rand_nums(vector<int> &vec); 

int main(){
	printf("before sort:");
	vector<int> vec;
	Rand_nums(vec);
	for_each(vec.begin(), vec.end(), printval);
	printf("\n");
	printf("alfter sort:");
	//冒泡排序
//	Buble_Sort(vec);
//  for_each(vec.begin(), vec.end(), printval);
    
    // 快速排序
//	Quick_Sort(vec, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval);

	// 插入排序
//	Insert_Sort(vec);
//	for_each(vec.begin(), vec.end(), printval); 
	
	// 希尔排序
//	Shell_Sort(vec, 4);
//	for_each(vec.begin(), vec.end(), printval);
	
	// 选择排序 
	Insertion_Sort(vec); 
	for_each(vec.begin(), vec.end(), printval); 
	 
	return 0;
}

/*
	// srand() 用于设定随机种子
	// 产生 范围为 [1,max]
	// int num = rand() % max + 1
	// 产生 任意范围 [min, max]
	// int num = rand() % (max - min + 1) + min
*/
void Rand_nums(vector<int> &vec){
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
	printf("%d ", val);
} 

void Buble_Sort(vector<int> &vec){
	for(int i = 0; i<vec.size()-1; i++){
		for(int j = i+1; j<vec.size(); j++){
			if(vec[j] < vec[i]) swap(vec[j], vec[i]);
		}
	}
}

void Quick_Sort(vector<int> &vec, int l, int r){
	if( l>= r) return;
	int base_val = vec[l];
	int left = l;
	int right = r;
	bool flag = false;
	while(l!=r){
		if(!flag){
			if(vec[r] < base_val){
				vec[l] = vec[r];
				l++;
				flag = true;
			}else{
				r--;
			}	
		}else{
			if(vec[l] > base_val){
				vec[r] = vec[l];
				r--;
				flag = false;
			}else{
				l++;
			}
		}
	}
	vec[l] = base_val;
	Quick_Sort(vec, left, l);
	Quick_Sort(vec, l+1, right);
}

void Insert_Sort(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		for(int j=i-1; j>=0; j--){
			if(vec[j+1] < vec[j]) swap(vec[j], vec[j+1]);
			else break;
		}
	}
}

void Shell_Sort(vector<int> &vec, int n){
	while(n!=0){
		for(int k=0; k<n; k++){
			for(int i=n; i<vec.size(); i+=n){
				for(int j=i-n; j>=0; j-=n){
					if(vec[j+1] < vec[j]) swap(vec[j], vec[j+1]);
					else break;
				}
			}
		}
		n = n/2;
	}
}
 
void Insertion_Sort(vector<int> &vec){
	for(int i=0; i<vec.size()-1; i++){
		int min = i;
		for(int j=i+1; j<vec.size(); j++){
			 if(vec[j] < vec[min]) min = j;
		}
		swap(vec[min], vec[i]);
	}
}

