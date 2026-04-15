#include <bits/stdc++.h>
using namespace std;

long long bfs_sum_steps(int n) {
	int totalStates = 1 << n;
	int start = totalStates - 1; // 全亮
	const int INF = -1;
	
	// dist[state][parity], parity=0 表示下一步为奇数步(后缀), 1 表示下一步为偶数步(前缀)
	vector<array<int,2>> dist(totalStates, {INF, INF});
	queue<pair<int,int>> q;
	
	dist[start][0] = 0;
	q.push({start, 0});
	
	while (!q.empty()) {
		pair<int, int> current = q.front();q.pop();
		int state = current.first;
		int parity = current.second;
		int d = dist[state][parity];
		
		if (parity == 0) {
			// 奇数步：翻转后缀 i..n
			for (int i = 0; i < n; i++) {
				int mask = (1 << (n - i)) - 1; // 低位 n-i 个 1
				int nextState = state ^ (mask << i);
				if (dist[nextState][1] == INF) {
					dist[nextState][1] = d + 1;
					q.push({nextState, 1});
				}
			}
		} else {
			// 偶数步：翻转前缀 1..i
			for (int i = 0; i < n; i++) {
				int mask = (1 << (i + 1)) - 1;
				int nextState = state ^ mask;
				if (dist[nextState][0] == INF) {
					dist[nextState][0] = d + 1;
					q.push({nextState, 0});
				}
			}
		}
	}
	
	long long total = 0;
	for (int s = 0; s < totalStates; s++) {
		int best = dist[s][0];
		if (best == -1 || (dist[s][1] != -1 && dist[s][1] < best)) {
			best = dist[s][1];
		}
		total += best;
	}
	return total;
}

int main() {
	for (int n = 1; n <= 5; n++) {
		cout << n << " " << bfs_sum_steps(n) << "\n";
	}
	return 0;
}
