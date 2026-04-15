#include<bits/stdc++.h>
#define L
using namespace std;
void quick_sort(int *nums,int l, int r){
	if(l >= r) return;	//应该包含非法区域所以改为l>=r
	int i = l, j = r;
	int pivot = nums[i];
	while(i < j){
		while(i < j && pivot <= nums[j]) j--;
		nums[i] = nums[j];
		while( i < j && pivot >= nums[i]) i++;
		nums[j] = nums[i];
	}
	nums[i] = pivot;
	quick_sort(nums,l,i-1);
	quick_sort(nums,i+1,r);
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	
	
	return 0;
}
