#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int T;
	cin >> T;
	while(T--){
		ll a,b,c;
		cin >> a >> b >> c;
		ll min_tmp = min(a,b);
		ll min_y = min(min_tmp,c);
		if(a-min_y >=2 || b-min_y >= 2 || c-min_y >= 2) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	return 0;
}
	
