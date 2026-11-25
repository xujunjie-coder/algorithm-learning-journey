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
int const N = 15;
int m[N][N];
int col[N];		//标记第i行的col[i]列放置牛牛
char ans[N][N];
bool flag[N];	//标记i号区域是否放置
int n;
bool right(int x,int y){
	// 只需要检查上方、左上、右上（因为按行放，下方还没放）
	if (ans[x-1][y] == 'X') return false;    // 正上
	if (ans[x-1][y-1] == 'X') return false;  // 左上
	if (ans[x-1][y+1] == 'X') return false;  // 右上
	return true;
}

int dfs(int cur){
	if(cur == n+1){
		return 1;
	}
	for(int i = 1; i <= n; ++i){
		int ok = 1;
		col[cur] = i;	//把第cur行放入i列
		if(flag[m[cur][i]]) continue;
		else flag[m[cur][i]] = true;
		ans[cur][i] = 'X';
		for(int j = 1; j < cur; ++j){
			if(col[cur] == col[j] || right(cur,i)){
				ok = 0;
				ans[cur][i] = '.';
				flag[m[cur][i]] = false;
				break;
			}
		}
		if(ok) dfs(cur+1);
	}
	return 0;
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> m[i][j];
		}
	}

	if(dfs(1)){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(ans[i][j] != 'X') cout << "." << " ";
				else cout << "X" << " ";
			}
			cout << "\n";
		}
	}else{
		cout << "No solution" << "\n";
	}
	return 0;
}
