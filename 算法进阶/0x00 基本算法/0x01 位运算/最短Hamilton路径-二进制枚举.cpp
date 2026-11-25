#include <bits/stdc++.h>

using namespace std;

int const N = 20;
int const INF = 0x3f3f3f3f;
int n;
int a[N][N];
int f[1 << N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    int all = (1 << n) - 1;
    for(int s = 1; s <= all; s += 2){
        for(int j = 1; j < n; ++j){
            if((s & (1 << j)) == 0) continue;
            if(j == n - 1 && s != all) continue;

            int pre = s ^ (1 << j);
            for(int k = 0; k < n; ++k){
                if((pre & (1 << k)) == 0) continue;
                if(f[pre][k] == INF) continue;

                f[s][j] = min(f[s][j], f[pre][k] + a[k][j]);
            }
        }
    }

    cout << f[all][n - 1] << "\n";
    return 0;
}