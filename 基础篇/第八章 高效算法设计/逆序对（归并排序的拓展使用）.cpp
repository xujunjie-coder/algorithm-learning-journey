#include<bits/stdc++.h>
#define L
using namespace std;
typedef long long ll;
int const N = 5e5+10;
ll a[N];
ll b[N];
int n;
ll tot;
ll solve(ll* a,int l, int r,ll *b){
	if(r - l == 1) return 0;
	int mid = l + (r-l)/2;
	ll tot = 0;
	tot += solve(a,l,mid,b);
	tot += solve(a,mid,r,b);
	int x = l, y = mid, i = l;
	while(x < mid || y < r){
		if(y >= r || (x < mid && a[x] <= a[y])) b[i++] = a[x++];
		else {
			b[i++] = a[y++];
			tot += mid-x;
		}
	}
	for(int i = l; i < r; i++) a[i] = b[i];
	return tot;
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){ cin >> a[i];}
	ll ans = solve(a,0,n,b);
	cout << ans;
	return 0;
}
