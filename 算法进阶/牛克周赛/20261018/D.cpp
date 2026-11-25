#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 2e6+5;
int a[N];
ll f[N];
ll pos[30*N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){ 
        cin >> a[i];
        f[i] = a[i] + f[i-1];
        pos[f[i]] = i;
    }
    int ans = 0;
    for(int l = 1; l <= n-2; ++l){
        for(int r = 1; r <= 30; ++r){
            int x = f[l]+a[l]*r;
            if(x < 0) continue;
            if(r == a[pos[x]+1] && pos[x]+1 - l + 1 >= 3){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}