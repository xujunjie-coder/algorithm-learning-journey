#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define Lo
#define ll long long
#define ull unsigned long long
#define endl '\n'

// 桌子范围：x[0,10], y[0,8]
int table[15][15];  // -1：不可通行，0：可通行，1：终点（充电接口）
int vis[15][15];    // 标记是否访问过
// 上下左右四个方向
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
int xc, yc;  // 电脑左上角坐标
int px, py;  // 手机充电接口坐标
int rx, ry;  // 手机剩余部分坐标

// BFS求最短路径点数
void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	int step = 1;  // 起点算1个点
	
	while (!q.empty()) {
		int len = q.size();  // 当前层的节点数
		for (int i = 0; i < len; ++i) {
			auto f = q.front();
			q.pop();
			int cur_x = f.first;
			int cur_y = f.second;
			
			// 到达终点，直接输出步数并返回
			if (table[cur_x][cur_y] == 1) {
				cout << step << endl;
				return;
			}
			
			// 遍历四个方向
			for (int j = 0; j < 4; ++j) {
				int nx = cur_x + dx[j];
				int ny = cur_y + dy[j];
				// 边界检查 + 未访问 + 可通行（0）或终点（1）
				if (nx >= 0 && nx <= 10 && ny >= 0 && ny <= 8 
					&& !vis[nx][ny] && table[nx][ny] != -1) {
					vis[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
		}
		step++;  // 遍历完一层，步数+1
	}
	
	// 遍历完所有点仍未找到终点
	cout << -1 << endl;
}

int main() {
#ifdef Lo
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 初始化table和vis为0（可通行）
	memset(table, 0, sizeof(table));
	memset(vis, 0, sizeof(vis));
	
	// 输入
	cin >> xc >> yc;   // 电脑左上角
	cin >> px >> py;   // 充电接口
	cin >> rx >> ry;   // 手机剩余部分
	yc = 8 - yc;
	py = 8 - py;
	ry = 8 - ry;
	// ========== 1. 标记不可通行区域 ==========
	// （1）标记电脑区域：X∈[Xc,Xc+3]，Y∈[Yc-2,Yc]
	for (int x = xc; x <= xc + 3; ++x) {
		for (int y = yc - 2; y <= yc; ++y) {
			// 确保坐标在桌子范围内（防止输入越界）
			if (x >= 0 && x <= 10 && y >= 0 && y <= 8) {
				table[x][y] = -1;
			}
		}
	}
	
	// （2）标记手机剩余部分（不可通行）
	if (rx >= 0 && rx <= 10 && ry >= 0 && ry <= 8) {
		table[rx][ry] = -1;
	}
	
	// （3）标记充电接口（终点，可通行且是目标）
	if (px >= 0 && px <= 10 && py >= 0 && py <= 8) {
		table[px][py] = 1;
	}
	
	// ========== 2. 启动BFS：起点是桌子右上角(10,8) ==========
	bfs(10, 8);
	
	return 0;
}
