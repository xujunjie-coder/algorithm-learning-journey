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
