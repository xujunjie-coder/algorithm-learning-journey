#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

ll p[410];
ll const INF = 0x3f3f3f3f3f3f3f;
int L[400];
int R[400];
ll dp[410][410];
ll pos[410][410];

ll dfs(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l + 1 == r) {
        pos[l][r] = l;
        return dp[l][r] = p[l - 1] * p[l] * p[r];
    }
    if (l == r) return 0;
    ll ans = INF;
    int x = -1;
    for (int k = l; k < r; ++k) {
        if (ans > dfs(l, k) + dfs(k + 1, r) + p[l - 1] * p[k] * p[r]) {
            ans = dfs(l, k) + dfs(k + 1, r) + p[l - 1] * p[k] * p[r];
            x = k;
        }
    }
    pos[l][r] = x;
    return dp[l][r] = ans;
}

void print(int l, int r){
    if(l == r){
        cout << "A" << l;
        return;
    }
    int k = pos[l][r];
    print(l,k);
    cout << "*";
    if(k+1 < r) cout << "(";
    print(k+1,r);
    if(k+1 < r) cout << ")";
}

int main() {
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> p[i];
    }
    ll ans = dfs(1, n);
    print(1,n);
    cout << "\n";
    cout << ans;
    return 0;
}