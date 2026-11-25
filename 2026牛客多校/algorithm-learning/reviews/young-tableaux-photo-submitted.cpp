#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
int const N = 35;
int k;
ll n[5];
ll memo[31][16][11][8][7];

void init(){
    for (int i = 0; i <= n[0]; i++)
        for (int j = 0; j <= n[1]; j++)
            for (int k = 0; k <= n[2]; k++)
                for(int l = 0; l <= n[3]; ++l)
                    for(int m = 0; m <= n[4]; ++m)
                        memo[i][j][k][l][m] = -1LL;
}

ll  dfs(int a,int b,int c,int d,int e){
    if(a == n[0] && b == n[1] && c == n[2] && d == n[3] && e == n[4]) return 1;
    ll ans = 0;
    if(memo[a][b][c][d][e] != -1) ans += memo[a][b][c][d][e];
    else{
        if(a < n[0]) ans += dfs(a+1,b,c,d,e);
        if(b < n[1] && a >= b+1){
            ans += dfs(a,b+1,c,d,e);
        }
        if(c < n[2] && b >= c+1){
            ans += dfs(a,b,c+1,d,e);
        }
        if(d < n[3] && c >= d+1){
            ans += dfs(a,b,c,d+1,e);
        }
        if(e < n[4] && d >= e+1){
            ans += dfs(a,b,c,d,e+1);
        }
    }
    memo[a][b][c][d][e] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> k && k){
        fill(n, n + 5, 0LL);
        for(int i = 0; i < k; ++i) cin >> n[i];
        init();
        cout << dfs(0,0,0,0,0) << "\n";
    }

    return 0;
}
