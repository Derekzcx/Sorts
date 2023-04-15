/*
 * ������ʵ�ֿ������� 
 * ƽ��ʱ�临�Ӷȣ�nlogn 
 *
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	1. Ĭ��ѡȡ��һΪ��׼ֵpivot����ʱ��һ��Ԫ�ص�λ�þͿճ����� 
	2. ��r�ұ߿�ʼ��pivot�Ƚϣ���pivotС���͸�ֵ����һ��Ԫ�ص�λ��l��l++����ͼ����Ƚ���һ�� 
    3.��ѰʱֻҪһ�α� pivot С����������Ƚϣ��͸ô����l��ʼ�Ƚϣ�ͬ��ֻҪ������pivot��ģ�������ֵ������r��r--��
	4. ��r �� l ���ʱ����Ѱ���ˣ����r��l��ȵ�λ�þ��� pivot ֵ�÷ŵ�λ�� 
*/ 

void Quick_Sort(vector<int> &vec, int l, int r){
	if(l>=r) return; // �ݹ�ĳ�������Ϊ l������߽� ���ڻ�С�� r������߽� 
	int pivot = vec[l]; // ���׼��Ϊ vec[pivot];
	int l_new = l;
	int r_new = r;
	bool flag = true; // ʹ��flag�������޶������һ�ָ���Ѱ������Ѱ 
	while(l != r){
		if(flag){ // ��Ѱ�� 
			if(vec[r] <= pivot){
				vec[l] = vec[r];
				l++;
				flag = false;
			}else{ // �����������Ѱ 
				r--;
			}
		}else{ // ��Ѱ�� 
			if(vec[l] > pivot){
				vec[r] = vec[l];
				r--; 
				flag = true;
			}else{ // �����������Ѱ 
				l++;
			}
		}
	} 
	vec[l] = pivot; // ��l��r���ʱ�ĵط����ǣ���׼ֵ�÷ŵĵط� 
	Quick_Sort(vec,l_new,l-1); // ͨ���޶������ķ�Χ���еݹ� 
	Quick_Sort(vec,l+1,r_new);
} 

void printval(int val){
	printf("%d ", val);
}
int main(){
	
	vector<int> test_vec = {2,4,5,1,6,2,7,8,10};
	Quick_Sort(test_vec, 0, test_vec.size()-1);
	for_each(test_vec.begin(), test_vec.end(), printval);
	return 0;
}
