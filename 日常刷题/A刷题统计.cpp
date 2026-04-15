#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,n,ans;

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> a >> b >> n;
	ll tWeek = a*5 + b*2;
	ll d = n / tWeek;
	ans = d * 7;
	ll d1 = n % tWeek;
	
	for(int i = 0; i < 7; ++i){
		if(i >= 5) d1 -= b;
		else d1 -= a;
		
		if(d1 <= 0){
			ans += i + 1;  
			break;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
