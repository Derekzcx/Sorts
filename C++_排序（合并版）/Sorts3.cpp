#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib> 
#include<algorithm>

using namespace std;

/******************** �㷨���� ************************/
//1 ð�� n^2 
void Bubble_Sort(vector<int> &vec){
	for(int i=0; i<vec.size()-1; i++){
		for(int j = i+1; j<vec.size(); j++){
			if(vec[i] > vec[j]) swap(vec[i],vec[j]);
		}
	}
} 
//2 ���� nlogn 
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

//3 �������� n^2
void Insert_Sort(vector<int> &vec){
	for(int i=1; i<vec.size(); i++){
		for(int j=i-1; j>=0; j--){
			if(vec[j+1] < vec[j]) swap(vec[j], vec[j+1]);
			else break;
		}
	}
} 

//4 ϣ������ n^1.3������2 Ϊ�����n 
void Shell_Sort(vector<int> &vec, int n){
	while(n!=0){
		for(int k=0; k<n; k++){
			for(int i=n; i<vec.size(); i+=n){
				for(int j=i-n; j>=0; j-=n){
					if(vec[j+n]<vec[j])swap(vec[j], vec[j+n]);
					else break;
				}
			}	
		}
		n = n/2;
	}
}

//5 �鲢���� nlogn
void Merga_Sort(vector<int> &vec, vector<int> tmp, int l, int r){
	if(l>=r) return;
	int left1 = l;
	int right1 = (l+r)/2;
	int left2 = right1 + 1;
	int right2 = r;
	Merga_Sort(vec, tmp, left1, right1);
	Merga_Sort(vec, tmp, left2, right2);
	
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
		tmp[k] = vec[left2];
		left2++; 
		k++;
	}
	for(int k=l; k<=r; k++){
		vec[k] = tmp[k];
	}
} 


//6 ������ nlogn, ����2��ʾ�Ѷ���n��ʾ�ѵĽ�ֹλ�� 
void heapify(vector<int> &vec, int i, int n){
	if(i >=n) return;
	int last_node = i;
	int left_son = 2*i+1;
	int right_son = 2*i+2;
	if(left_son < n && vec[left_son] > vec[last_node]) last_node = left_son;
	if(right_son < n && vec[right_son] > vec[last_node]) last_node = right_son;
	if(last_node != i){
		swap(vec[last_node], vec[i]);
		heapify(vec, last_node ,n);
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

// 7 ѡ������ n^2 , ѡ����� 
void Insertion_Sort(vector<int> &vec){
	for(int i=0; i<vec.size()-1; i++){
		int min = i;
		for(int j=i+1; j<vec.size(); j++){
			if(vec[min] > vec[j]) min = j;
		}
		if(min != i) swap(vec[i], vec[min]);
	}
}
// 8 �������� �ǱȽ�����
vector<int> Count_Sort(vector<int> &vec){
	int max = *max_element(vec.begin(), vec.end());
	vector<int> tmp1(max+1, 0);
	for(int i=0; i<vec.size(); i++){
		tmp1[vec[i]]++;
	}
	vector<int> tmp2(max+1, 0);
	int sum = 0;
	for(int i=0; i<tmp1.size(); i++){
		sum += tmp1[i];
		tmp2[i] = sum;
	}
	vector<int> tmp3(vec.size(), 0);
	for(int i=0; i<vec.size(); i++){
		int pos = tmp2[vec[i]];
		tmp3[pos-1] = vec[i];
		tmp2[vec[i]]--;
	}
	return tmp3;
}

// 9 �������� �ǱȽ����� 
void Redix_Sort(vector<int> &vec){
	int max = *max_element(vec.begin(), vec.end());
	int n = 0;
	while(max != 0){
		n++;
		max/=10;
	} 
	vector<queue<int>> que_vec(10, queue<int>());
	 for(int k=0; k<n; k++){
	 	for(int i=0; i<vec.size(); i++){
	 		int num = pow(10, k);
	 		int tmp = (vec[i]/num)%10;
	 		que_vec[tmp].push(vec[i]);
	 	}
	 	vec.clear();
	 	for(int i=0; i<10; i++){
	 		while(!que_vec[i].empty()){
	 			vec.emplace_back(que_vec[i].front());
	 			que_vec[i].pop();
			 }
		}
	 }
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
	//Insert_Sort(vec); 
	// ϣ������ 
	//Shell_Sort(vec, 6);
	// �鲢����
	//vector<int> tmp(vec.size(), 0);
	//Merga_Sort(vec, tmp, 0, vec.size()-1);
	// ������
	//Heap_Sort(vec, vec.size()); 
	// ѡ������
	//Insertion_Sort(vec); 
	// ��������
	vector<int> tmp_val = Count_Sort(vec);  
	// ��������
	Redix_Sort(vec); 
	for_each(vec.begin(), vec.end(),printval);
	return 0;
}
