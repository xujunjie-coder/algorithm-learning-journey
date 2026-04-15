#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
int n,m;
int const N = 1010;
int maze[N][N];
int id[N][N]; 
int id_cnt;
int ans[N*N];   //ans[id] = tot;   
int tot;
queue< pair<int,int> > q;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void bfs(int sx, int sy){
	id_cnt++;
	q.push({sx,sy});
	id[sx][sy] = id_cnt;
	tot = 1;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		int x = t.first;
		int y = t.second; 
		int flag = 0;
		if(maze[x][y]) flag = 1;
		for(int i = 0; i < 4; ++i){
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
			if(id[xx][yy]) continue;
			if(flag){
				if(maze[xx][yy]) continue;
				else{
					id[xx][yy] = id_cnt;
					tot++;
					q.push({xx,yy});
				}
			}else{
				if(!maze[xx][yy]) continue;
				else{
					id[xx][yy] = id_cnt;
					tot++;
					q.push({xx,yy});
				}
			}
		}
	}
	ans[id_cnt] = tot;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		s = " " + s;
		for(int j = 1; j <= n; ++j)
			maze[i][j] = s[j] - '0';
	}
	//pretreatment
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(id[i][j] == 0)
				bfs(i,j);
		}
	}
	while(m--){
		int x,y;
		cin >> x >> y;
		cout << ans[id[x][y]] << "\n";
	}
	return 0;
}
