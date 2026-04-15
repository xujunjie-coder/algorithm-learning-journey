#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 5e5+10;
int n,q;
ll a[N];
ll f[N];
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		f[i] = a[i] - a[i-1];
	}
	for(int i = 1; i <= q; ++i){
		int l,r;
		ll d;
		cin >> l >> r >> d;
		f[l] += d;
		f[r+1] -= d;
	}
	for(int i = 1; i <= n; ++i){
		f[i] = f[i-1] + f[i];
		cout << f[i] << " ";
	}
	return 0;
}
