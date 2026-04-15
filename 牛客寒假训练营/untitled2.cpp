#include <bits/stdc++.h>
using namespace std;
int m,n;
int const N = 1010;
int f[N];
vector< pair<int,int> > g[N];	//g[i]为组数为i时的物品，piarfirst = 重量；second = 价值

int main(){
	cin >> m >> n;
	int cnt = 0;	//记录最大的组号（即总组数）
	for(int i = 1; i <= n; ++i){
		int x,y,z;
		cin >> x >> y >> z;
		cnt = max(cnt,z);
		g[z].push_back({x,y});
	}
	
	for(int i = 1; i <= cnt; ++i){
		for(int j = m; j >= 0; --j){
			//在这一组中选择物品
			for(auto& t : g[i]){
				int a = t.first;
				int b = t.second;
				if(j >= a){
					f[j] = max(f[j],f[j-a] + b);
				}
			}
		}
	}
	cout << f[m];
	return 0;
}
