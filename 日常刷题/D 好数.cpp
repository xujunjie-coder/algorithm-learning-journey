#include<bits/stdc++.h>
#define L
using namespace std;
bool isGood(string s){
	reverse(s.begin(),s.end());
	s = " " + s;
	int len = s.length();
	for(int i = 1; i < len; ++i){
		if(i % 2 == 1) {
			if(s[i] % 2 == 0) return false;
		}else{
			if(s[i] % 2 == 1) return false;
		}
	}
	return true;
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		string s = to_string(i);
		if(!isGood(s)) continue;
		ans++;
	}
	cout << ans;
	return 0;
}
