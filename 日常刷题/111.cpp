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
int table[15][15];
int vis[15][15];
int dx[] = { 0,1,-1,0 };
int dy[] = { -1,0,0,1 };
int xc,yc;	//computer
int px,py;	//target
int rx,ry;  //phone
int tot = 1;
void bfs(int sx,int sy){
	queue<pair<int,int>> q;
	q.push({sx,sy});
	vis[sx][sy] = 1;
	while(!q.empty()){
		int len = q.size();
		for(int i = 0; i < len; ++i){
			auto f = q.front(); 
			q.pop();
			for(int j = 0; j < 4; ++j){
				int x = dx[j]+f.first;
				int y = dy[j]+f.second;
				if(x >= 0 && x <= 10 && y >= 0 && y <= 8 && table[x][y] != -1 && vis[x][y] != 1){
					if(table[x][y] == 0){
						q.push({x,y});
						vis[x][y] = 1;
					}
					if(table[x][y] == 1){
						cout << tot;
						return;
					}
				}
			}
		}
		tot++;
	}
	cout << -1;
	return;
}
int main()
{
#ifdef Lo
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> xc >> yc;
	cin >> px >> py;
	cin >> rx >> ry;
	
	py = 8 - py;
	ry = 8 - ry;
	for(int i = xc; i <= xc + 3; i++){
		for(int j = yc; j <= yc + 10; j ++){
			table[i][j] = -1;
		}
	}
	for(int i = xc; i <= xc + 3; i++){
		for(int j = yc; j <= 10 - yc; j ++){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	table[px][py] = 1;
	table[rx][ry] = -1;
	bfs(8,0);
	return 0;
}
