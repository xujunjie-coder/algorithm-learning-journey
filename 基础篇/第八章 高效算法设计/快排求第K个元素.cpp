#include<bits/stdc++.h>
#define L
using namespace std;
int const N = 1e5 + 10;
int nums[N];
int quick_sort(int *nums,int l, int r, int k){
	int i = l, j = r;
	int pivot = nums[i];
	while(i < j){
		while(i < j && pivot <= nums[j]) j--;
		nums[i] = nums[j];
		while(i < j && pivot >= nums[i]) i++;
		nums[j] = nums[i];
	}
	nums[i] = pivot;
	if(k>i){
		quick_sort(nums, i+1, r, k);
	}else if(k < i){
		quick_sort(nums, l, i-1, k);
	}else return nums[i];
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int k;
	cin >> k;
	int i = 1;
	int len = 0;
	int t;
	while(cin >> t){
		nums[i++] = t;
		len ++;
	}
	
	
	
	return 0;
}
