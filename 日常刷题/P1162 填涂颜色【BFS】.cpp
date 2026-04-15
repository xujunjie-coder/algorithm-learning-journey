#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define Lo

#define ll long long
#define ull unsigned long long
#define endl '\n'

int const N = 35;
int maze[N][N];
int maze_cp[N][N];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int vis[N][N];
int n;

void bfs(int sx, int sy){
	queue<pair<int,int>> q;
	q.push({sx,sy});
	vis[sx][sy] = 1;
	maze_cp[sx][sy] = -1;
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int x = dx[i] + f.first;
			int y = dy[i] + f.second;
			if(x <= n && x > 0 && y <= n && y > 0 && maze[x][y] != 1 && vis[x][y] != 1){
				q.push({x,y});
				maze_cp[x][y] = -1;
				vis[x][y] = 1;
			}
		}
	}
}
int main()
{
#ifdef Lo
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			cin >> maze[i][j];
	}
	memcpy(maze_cp,maze,sizeof maze);
	
	for(int j = 1; j <= n; ++j){
		if(!maze[1][j]) bfs(1,j);		
	}
	for(int j = 1; j <= n; ++j){
		if(!maze[n][j]) bfs(n,j);
	}
	for(int i = 1; i <= n; ++i){
		if(!maze[i][1]) bfs(i,1);
	}
	for(int i = 1; i <= n; ++i){
		if(!maze[i][n]) bfs(i,n);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(maze_cp[i][j] == 0){
				maze[i][j] = 2;
			}
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
