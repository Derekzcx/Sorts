#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib> // rand() �� srand() ��Ҫ
#include<ctime>  // ʹ�� time ��Ҫ 

using namespace std;

// ð������ ��ƽ��ʱ�临�Ӷ�Ϊ n^2 
void Buble_Sort(vector<int> &vec);

// ���ţ�ƽ��ʱ�临�Ӷ�Ϊ nlogn : �β� l��r�ֱ��ʾͷβ�±� 
void Quick_Sort(vector<int> &vec, int l, int r);

// ��������ƽ��ʱ�临�Ӷ�Ϊ n^2
void Insert_Sort(vector<int> &vec); 

// ϣ������ƽ��ʱ�临�Ӷ�Ϊ n^1.3: �β� n ��ʾ����� 
void Shell_Sort(vector<int> &vec, int n); 
 
// ѡ������, ƽ��ʱ�临�Ӷ�Ϊ n^2 
void Insertion_Sort(vector<int> &vec);

// ��ӡ���� 
void printval(int &val);

// �����������������
void Rand_nums(vector<int> &vec); 

int main(){
	printf("before sort:");
	vector<int> vec;
	Rand_nums(vec);
	for_each(vec.begin(), vec.end(), printval);
	printf("\n");
	printf("alfter sort:");
	//ð������
//	Buble_Sort(vec);
//  for_each(vec.begin(), vec.end(), printval);
    
    // ��������
//	Quick_Sort(vec, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval);

	// ��������
//	Insert_Sort(vec);
//	for_each(vec.begin(), vec.end(), printval); 
	
	// ϣ������
//	Shell_Sort(vec, 4);
//	for_each(vec.begin(), vec.end(), printval);
	
	// ѡ������ 
	Insertion_Sort(vec); 
	for_each(vec.begin(), vec.end(), printval); 
	 
	return 0;
}

/*
	// srand() �����趨�������
	// ���� ��ΧΪ [1,max]
	// int num = rand() % max + 1
	// ���� ���ⷶΧ [min, max]
	// int num = rand() % (max - min + 1) + min
*/
void Rand_nums(vector<int> &vec){
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

