#include<bits/stdc++.h>
//#define L
using namespace std;
int const N = 2e5+10;
int n;
int a[N];

int maxsum(int* a,int l, int r){	//左闭右开
	if(r - l == 1) return a[l];	//终止条件
	int mid = l + (r-l)/2;
	//求左右两边的最大值
	int l_max = maxsum(a,l,mid);
	int r_max = maxsum(a,mid,r);
	int maxx = max(l_max,r_max);
	//求以mid为中界线，往左和往右的最大值；
	int lsum = 0, rsum = 0;
	int lMax = -1e5,rMax = -1e5;
	for(int i = mid - 1; i >= l; i--) lMax = max(lMax,lsum += a[i]);
	for(int i = mid; i < r; i++) rMax = max(rMax,rsum += a[i]);
	return max(maxx,lMax+rMax);
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = maxsum(a,0,n);
	cout << ans;
	return 0;
}
