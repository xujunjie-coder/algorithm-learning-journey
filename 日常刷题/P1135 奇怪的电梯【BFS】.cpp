#include<bits/stdc++.h>
#define L
using namespace std;
int const N = 220;
int k[N];
queue<int> q;
int vis[N];
int n,a,b;
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n >> a >> b;
	for(int i = 1; i <= n; ++i) cin >> k[i];
	q.push(a);
	vis[a] = 1;
	int ans = 0;
	while(!q.empty()){
		int len = q.size();
		for(int i = 0; i < len; ++i){
			int x = q.front();
			q.pop();
			if(x == b){
				cout << ans;
				return 0;
			}
			if(x+k[x] <= n && !vis[x+k[x]]){
				q.push(x+k[x]);
				vis[x+k[x]] = 1;
			}
			if(x-k[x] >= 1 && !vis[x-k[x]]){
				q.push(x-k[x]);
				vis[x-k[x]] = 1;	
			}
		}
		ans++;	
	}
	cout << -1;
	
	
	return 0;
}
