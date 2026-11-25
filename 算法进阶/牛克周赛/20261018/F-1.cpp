#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n;
ll s;
int const N = 4010;
int a[N],b[N];
ll L[N][N/4],R[N][N/4];    //在前i个长度选j个的最小费用
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    //dp
    //初始化
    memset(L,0x3f,sizeof L);
    memset(R,0x3f,sizeof R);
    for(int i = 0; i <= n; ++i){
        L[i][0] = 0;
        R[i][0] = 0;
    }
    L[1][1] = a[1];
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= (n+1)/4; ++j){
            L[i][j] = L[i-1][j];
            if(i >= 2){
                L[i][j] = min(L[i][j],L[i-2][j-1]+a[i]);
            }
        }
    }
    R[n][1] = b[n];
    for(int i = n-1; i >= 1; --i){
        for(int j = 1; j <= (n+1)/4; ++j){
            R[i][j] = R[i+1][j];
            if(i <= n-2){
                R[i][j] = min(R[i][j],R[i+2][j-1]+b[i]);
            }
        }
    }

    int k = 0;
    //枚举分界线
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= (n+1)/4; ++j){
            if(L[i-1][j] + R[i+1][j] <= s) k = max(k,j);
        }
    }
    cout << k << "\n";
    return 0;
}