/*
 * 本程序：实现快速排序 
 * 平均时间复杂度：nlogn 
 *
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	1. 默认选取第一为基准值pivot，此时第一个元素的位置就空出来了 
	2. 从r右边开始与pivot比较，比pivot小，就赋值给第一个元素的位置l，l++，大就继续比较下一个 
    3.右寻时只要一次比 pivot 小的数，做完比较，就该从左边l开始比较，同样只要出现了pivot大的，就做赋值操作给r，r--；
	4. 当r 与 l 相等时，就寻完了，这个r与l相等的位置就是 pivot 值该放的位置 
*/ 

void Quick_Sort(vector<int> &vec, int l, int r){
	if(l>=r) return; // 递归的出口条件为 l左区间边界 大于或小于 r右区间边界 
	int pivot = vec[l]; // 则基准数为 vec[pivot];
	int l_new = l;
	int r_new = r;
	bool flag = true; // 使用flag参数来限定这个这一轮该右寻还是左寻 
	while(l != r){
		if(flag){ // 右寻先 
			if(vec[r] <= pivot){
				vec[l] = vec[r];
				l++;
				flag = false;
			}else{ // 不满足则继续寻 
				r--;
			}
		}else{ // 左寻次 
			if(vec[l] > pivot){
				vec[r] = vec[l];
				r--; 
				flag = true;
			}else{ // 不满足则继续寻 
				l++;
			}
		}
	} 
	vec[l] = pivot; // 当l和r相等时的地方就是，基准值该放的地方 
	Quick_Sort(vec,l_new,l-1); // 通过限定操作的范围进行递归 
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
