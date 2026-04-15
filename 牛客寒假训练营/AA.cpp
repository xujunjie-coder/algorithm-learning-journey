#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int main(){

	int n;
	cin >> n;
	double cp_num = (n-1) * 0.8;
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		b[a[i]] ++;
		c[a[i]] ++;
	}
	for(int i = 1; i <= MAXN; ++i){
		b[i] += b[i-1];
	}
	for(int i = 1; i <= MAXN; ++i){
		b[i] = b[i] - c[i];
	}
	for(int i = 1; i <= n; ++i){
		if(b[a[i]] >= cp_num) sum +=a[i];
	}
	cout << sum << "\n";
	return 0;
}
