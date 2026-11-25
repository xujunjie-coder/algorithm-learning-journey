#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5050;
int a[N];
int f[N];   //以i结尾的最长上升子序列长度


int main(){

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		f[i] = 1;   //初始化，对于每个子串至少都是长为一
		for(int j = 1; j < i; ++j){
			if(a[i] > a[j]){
				f[i] = max(f[i],f[j] + 1);
			}
		}
		ans = max(ans,f[i]);
	}
	cout << ans;
	return 0;
}