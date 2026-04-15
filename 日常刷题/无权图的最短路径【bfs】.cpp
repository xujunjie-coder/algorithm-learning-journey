#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 1e6+5;
int const MOD = 100003;
vector<int> adj[N];
int dist[N];
int cnt[N];
int n,m;

void bfs(int s){
	memset(dist,-1,sizeof dist);
	dist[s] = 0;
	cnt[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto v : adj[f]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[f]+1;
				cnt[v] = cnt[f];
			}else if(dist[v] == dist[f]+1){
				cnt[v] = (cnt[v] + cnt[f])% MOD;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int x,y;
		cin >> x >> y;
		if(x == y) continue;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(1);
	for(int i = 1; i <= n; ++i){
		cout << cnt[i] << endl;
	}
	return 0;
}
