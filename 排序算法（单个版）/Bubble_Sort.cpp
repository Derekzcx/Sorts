/*
 * ������ʵ��ð������ 
 * ƽ��ʱ�临�Ӷȣ�n^2 
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// flag Ϊtrue ��ʾ�Ӵ�С�ţ� flag Ϊfalse ��ʾ��С������ 
void Bubble_Sort(vector<int> &vec, bool flag = false){
	if(flag){
		for(int i=0; i<vec.size()-1; i++){
			for(int j=i+1; j<vec.size(); j++){
				if(vec[i]>vec[j]){
					swap(vec[i],vec[j]);
				}
			}
		}
		return;	
	}
	for(int i=0; i<vec.size()-1; i++){
			for(int j=i+1; j<vec.size(); j++){
				if(vec[i]<vec[j]){
					swap(vec[i],vec[j]);
				}
			}
		}
		return;
} 

void printval(int val){
	printf("%d ", val);
}
int main(){
	vector<int> test_vec = {2,4,5,1,6,2,7,8,10};
	
	Bubble_Sort(test_vec,true);
	
	for_each(test_vec.begin(), test_vec.end(), printval);
	
	return 0;
}
