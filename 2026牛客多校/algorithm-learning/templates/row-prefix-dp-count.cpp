// 契约：最多五排，行长不增，总人数 <= 30，不存在的排为 0；返回前缀安排数。空状态为 1。
// 来源：young-tableaux-photo；助手参考实现，2026-10-23 通过 358 组本地对照，无在线 AC 报告。
// 时间 O(5*乘积(n[i]+1))，固定缓存约 2.33 MiB；long long 计数。各状态人数范围 [0,n[i]]。
// 复用时修改容量输入；改变约束需重估维度并重新证明转移、遍历顺序与溢出界限。
// 助手提供的参考实现，非用户补交代码；验证结果见 young-tableaux-methods-verification.json。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int k;
ll n[5];
ll dp[31][16][11][8][7];

void init(){
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0][0] = 1;
}

void solve(){
    for(int a = 0; a <= n[0]; ++a)
        for(int b = 0; b <= n[1]; ++b)
            for(int c = 0; c <= n[2]; ++c)
                for(int d = 0; d <= n[3]; ++d)
                    for(int e = 0; e <= n[4]; ++e){
                        if(a < n[0])
                            dp[a+1][b][c][d][e] += dp[a][b][c][d][e];
                        if(b < n[1] && a >= b+1)
                            dp[a][b+1][c][d][e] += dp[a][b][c][d][e];
                        if(c < n[2] && b >= c+1)
                            dp[a][b][c+1][d][e] += dp[a][b][c][d][e];
                        if(d < n[3] && c >= d+1)
                            dp[a][b][c][d+1][e] += dp[a][b][c][d][e];
                        if(e < n[4] && d >= e+1)
                            dp[a][b][c][d][e+1] += dp[a][b][c][d][e];
                    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> k && k){
        fill(n, n+5, 0LL);
        for(int i = 0; i < k; ++i) cin >> n[i];
        init();
        solve();
        cout << dp[n[0]][n[1]][n[2]][n[3]][n[4]] << '\n';
    }
}

