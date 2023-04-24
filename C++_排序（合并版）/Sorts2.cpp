#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib> // rand() �� srand() ��Ҫ
#include<ctime>  // ʹ�� time ��Ҫ 
#include<cmath>

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

// �鲢����ƽ��ʱ�临�Ӷ�Ϊ nlogn
void Merge_Sort(vector<int> &vec, vector<int> &tmp, int l, int r); 

// ������ ƽ��ʱ�临�Ӷ�Ϊ nlogn, i��ʾ���ڵ㣬n��ʾ��ֹ�±� 
void heapify(vector<int> &vec, int i, int n);
void Heap_Sort(vector<int> &vec, int n);

// �������� �ǱȽ�����o(n+k)
void Count_Sort(vector<int> &vec, vector<int> &out);

// �������򣬷ǱȽ�����
void Reix_Sort(vector<int> &vec);

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
//	Insertion_Sort(vec); 
//	for_each(vec.begin(), vec.end(), printval);

	// �鲢���� 
//	vector<int> tmp(vec.size(), 0);
//	Merge_Sort(vec, tmp, 0, vec.size()-1);
//	for_each(vec.begin(), vec.end(), printval); 
	 
	// ������
//	Heap_Sort(vec, vec.size());
//	for_each(vec.begin(), vec.end(), printval); 

	// ��������
//	vector<int> result(vec.begin(), vec.end());
//	Count_Sort(vec, result);
//	for_each(result.begin(), result.end(), printval); 
	
	// �������� 
	Reix_Sort(vec);
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

void Merge_Sort(vector<int> &vec, vector<int> &tmp, int l, int r){
	if(l>=r) return;
	// ���� 
	int left1 = l;
	int right1 = (l+r)/2;
	int left2 = right1 + 1;
	int right2 = r;
	Merge_Sort(vec, tmp, left1, right1);
	Merge_Sort(vec, tmp, left2, right2);
	// �ϲ�
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
	// ���� 
	for(int i=(n-1-1)/2; i>=0; i--){
		heapify(vec, i, n);
	}
	// ά���ѵ�����
	for(int i=n-1; i>=0; i--){
		swap(vec[0], vec[i]);
		heapify(vec, 0, i);
	} 
}

void Count_Sort(vector<int> &vec, vector<int> &out){
	int max = *max_element(vec.begin(),vec.end());
	vector<int> tmp1(max+1, 0);//�±��ʾԪ��ֵ�� ���ݱ�ʾ���� 
	vector<int> tmp2(max+1, 0);// �±��ʾԪ��ֵ�� ���ݱ�ʾλ��
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
