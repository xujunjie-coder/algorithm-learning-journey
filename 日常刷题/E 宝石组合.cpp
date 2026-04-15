#include<bits/stdc++.h>
#define L
using namespace std;
typedef long long ll;
int const N = 1e5+10;
int n,h[N];
int gcd(int x,int y){
	while(y){
		int t = y;
		y = x%y;
		x = t;
	}
	return x;
}
int lcm(int a,int b){
	return a / gcd(a,b) * b;
}
int lcm(int a,int b,int c){
	return lcm(lcm(a,b),c);
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> h[i];
	sort(h,h+n);
	ll maxs = 0;
	for(int i = 0; i + 3 <= n; ++i){
		for(int j = i; j + 3 <= n; ++j){
			ll a = h[j], b = h[j+1], c = h[j+2];
			maxs = max(maxs,a*b*c/(lcm(a,b)*lcm(a,c)*lcm(b,c)) * lcm(a,b,c));
		}
		
	}
	for(int i = 0; i + 3 < n; ++i){
		int flag = 0;
		for(int j = i; j + 3 <= n; ++j){
			ll a = h[i], b = h[i+1], c = h[i+2];
			ll s = a*b*c/(lcm(a,b)*lcm(a,c)*lcm(b,c)) * lcm(a,b,c);
			if(maxs == s) {
				cout << a << " "<< b << " " << c; 
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	return 0;
}
