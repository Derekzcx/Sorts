#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib> // rand() 和 srand() 需要
#include<ctime>  // 使用 time 需要 
#include<cmath>

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

// 归并排序，平均时间复杂度为 nlogn
void Merge_Sort(vector<int> &vec, vector<int> &tmp, int l, int r); 

// 堆排序， 平均时间复杂度为 nlogn, i表示父节点，n表示截止下标 
void heapify(vector<int> &vec, int i, int n);
void Heap_Sort(vector<int> &vec, int n);

// 计数排序， 非比较排序，o(n+k)
void Count_Sort(vector<int> &vec, vector<int> &out);

// 基数排序，非比较排序
void Reix_Sort(vector<int> &vec);

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
//	Insertion_Sort(vec); 
//	for_each(vec.begin(), vec.end(), printval);

	// 归并排序 
//	vector<int> tmp(vec.size(), 0);
//	Merge_Sort(vec, tmp, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval); 
	 
	// 堆排序
//	Heap_Sort(vec, vec.size());
//	for_each(vec.begin(), vec.end(), printval); 

	// 计数排序
//	vector<int> result(vec.begin(), vec.end());
//	Count_Sort(vec, result);
//	for_each(result.begin(), result.end(), printval); 
	
	// 基数排序 
	Reix_Sort(vec);
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

void Merge_Sort(vector<int> &vec, vector<int> &tmp, int l, int r){
	if(l>=r) return;
	// 分区 
	int left1 = l;
	int right1 = (l+r)/2;
	int left2 = right1 + 1;
	int right2 = r;
	Merge_Sort(vec, tmp, left1, right1);
	Merge_Sort(vec, tmp, left2, right2);
	// 合并
	int k = l;
	while(left1 <= right1 && left2 <= right2){
		if(vec[left1] <= vec[left2]){
			tmp[k] = vec[left1];
			left1++;
			k++;
		}else{
			tmp[k] = vec[left2];
			left2++;
			k++;
		}
	}
	while(left1 <= right1){
		tmp[k] = vec[left1];
		left1++;
		k++;
	}
	while(left2 <= right2){
		tmp[k]= vec[left2];
		left2++;
		k++;
	}
	for(int k=l; k<=r ; k++){
		vec[k] = tmp[k];
	}
}

void heapify(vector<int> &vec, int i, int n){
	if(i>=n) return;
	int last_node = i;
	int left_son = 2*i+1;
	int right_son = 2*i+2;
	if(left_son < n && vec[left_son] > vec[last_node]) last_node = left_son;
	if(right_son < n && vec[right_son] > vec[last_node]) last_node = right_son;
	if(last_node != i){
		swap(vec[last_node], vec[i]);
		heapify(vec, last_node, n);
	}
} 
void Heap_Sort(vector<int> &vec, int n){
	// 建堆 
	for(int i=(n-1-1)/2; i>=0; i--){
		heapify(vec, i, n);
	}
	// 维护堆的性质
	for(int i=n-1; i>=0; i--){
		swap(vec[0], vec[i]);
		heapify(vec, 0, i);
	} 
}

void Count_Sort(vector<int> &vec, vector<int> &out){
	int max = *max_element(vec.begin(),vec.end());
	vector<int> tmp1(max+1, 0);//下标表示元素值， 内容表示数量 
	vector<int> tmp2(max+1, 0);// 下标表示元素值， 内容表示位置
	for(auto i: vec){
		tmp1[i]++;
	} 
	int sum = 0;
	for(int i =0; i<tmp1.size(); i++){
		sum += tmp1[i];
		tmp2[i] = sum;
	}
	for(auto i: vec){
		int pos = tmp2[i];
		out[pos-1] = i;
		tmp2[i]--;
	}
}

void Reix_Sort(vector<int> &vec){
	int max = *max_element(vec.begin(), vec.end());
	int n = 0;
	while(max!=0){
		n++;
		max/=10;
	}
	queue<int> que;
	vector<queue<int>> vec_que(10, que);
	for(int k =0; k<n; k++){
		for(auto i:vec){
			int tmp = pow(10,k);
			int pos = (i/tmp)%10;
			vec_que[pos].push(i);
		}
		vec.clear();
		for(int i=0; i<10; i++){
			while(!vec_que[i].empty()){
				vec.emplace_back(vec_que[i].front());
				vec_que[i].pop();
			}
		}
	}
}
