#include<bits/stdc++.h>
#define L
using namespace std;

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int const N = 1010;
	int x[N][N] = {0}, y[N][N] = {0}, z[N][N] = {0};
	int n,q;
	int ans = 0;
	cin >> n >> q;
	while(q--){
		int a , b , c;
		cin >> a >> b >> c;
		x[a][b]++;
		y[a][c]++;
		z[b][c]++;
		if(x[a][b] == n){
			ans++;
		}
		if(y[a][c] == n){
			ans++;
		}
		if(z[b][c] == n){
			ans++;
		}
		cout << ans << "\n";
	}
	
	return 0;
}
