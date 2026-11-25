#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 5010;
int n,r;
int a[N][N]; 
ll f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    for(int i = 0; i < n; ++i){
        int x,y,v;
        cin >> x >> y >> v;
        a[++x][++y] += v;
    }

    for(int i = 1; i <= 5001; ++i){
        for(int j = 1; j <= 5001; ++j){
            f[i][j] = f[i-1][j] + f[i][j-1] + a[i][j] - f[i-1][j-1];
            //cerr << i << " " << j << " " <<f[i][j] << "\n";
        }
    }
    ll ans = 0;
    for(int i = 1; i + r - 1 <= 5001; ++i){
        for(int j = 1; j + r - 1 <= 5001; ++j){
            ll val = f[i+r-1][j+r-1] - f[i-1][j] - f[i][j-1] + f[i-1][j-1];
            ans = max(ans, val);
        }
    }
    cout << ans << "\n";
    return 0;
}