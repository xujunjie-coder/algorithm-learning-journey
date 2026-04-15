#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <string>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 1010;
char board[N][N];
int vis[N][N];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n,m;
int ans;
queue<pair<int,int>> q;
void bfs(int x, int y){
	q.push({x,y});
	vis[x][y] = 1;
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		for(int i = 0 ; i < 4; ++i){
			int tx = f.first + dx[i];
			int ty = f.second + dy[i];
			if(vis[tx][ty] == 0 && tx > 0 && tx <= n && ty > 0 && ty <= m && board[tx][ty] == '#'){
				q.push({tx,ty});
				vis[tx][ty] = 1;
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
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> board[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(board[i][j] == '#' && !vis[i][j]){
				bfs(i,j);
				ans++;
			}
		}
	}
	if(ans > 0)
		cout << "There are " <<  ans << " ships." <<endl;
	else cout << "Bad placement." << endl;
	
	
	
	
	
	return 0;
}
