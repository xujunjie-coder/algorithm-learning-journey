#include <bits/stdc++.h>

using namespace std;

int const N = 20;
int n;
int a[N][N];
int flag[N];
int ans = INT_MAX;

void dfs(int cur, int last, int sum){
    if(cur >= n - 1){
        ans = min(ans, sum + a[last][n - 1]);
        return;
    }

    for(int i = 1; i < n - 1; ++i){
        if(flag[i]) continue;

        //剪枝
        int next = sum + a[last][i];
        if(next >= ans) continue;

        flag[i] = 1;
        dfs(cur + 1, i, next);
        flag[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    dfs(1, 0, 0);
    cout << ans << "\n";

    return 0;
}