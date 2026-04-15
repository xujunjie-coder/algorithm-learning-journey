#include<bits/stdc++.h>

using namespace std;
int const N = 1010;
string s;
int f[N][N];

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> s;
	int n = s.length();
	s = " " + s;
	for(int len = 1; len <= n; ++len){
		for(int i = 1; i + len - 1 <= n; ++i){
			int j = i + len - 1;
			if(s[i] == s[j]) f[i][j] = f[i+1][j-1];
			else f[i][j] = min(f[i+1][j],f[i][j-1]) + 1;
		}
	}
	cout << f[1][n];
	
	return 0;
}
