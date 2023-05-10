#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib> 
#include<algorithm>

using namespace std;

/******************** �㷨���� ************************/
// ð�� n^2 
void Bubble_Sort(vector<int> &vec){
	for(int i=0; i<vec.size()-1; i++){
		for(int j = i+1; j<vec.size(); j++){
			if(vec[i] > vec[j]) swap(vec[i],vec[j]);
		}
	}
} 
// ���� nlogn 
void Quick_Sort(vector<int> &vec, int l, int r){
	if(l>=r) return;
	int base_val = vec[l];
	int left = 1;
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

// �������� n^2
void Insert_Sort(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		for(int j=i-1; j>=0; j--){
			if(vec[j+1] < vec[j]) swap(vec[j], vec[j+1]);
			else break;
		}
	}
} 

void Shell_Sort(vector<int> &vec){
	
}

/******************** ���ߺ��� ************************/
void create_testval(vector<int> &vec){
	unsigned int seed = time(0); // �Ե�ǰʱ��Ϊ����
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
	// ð�� 
	//Bubble_Sort(vec);
	// ���� 
	//Quick_Sort(vec, 0, vec.size()-1); 
	// ��������
	Insert_Sort(vec); 
	for_each(vec.begin(), vec.end(),printval);
	return 0;
}
