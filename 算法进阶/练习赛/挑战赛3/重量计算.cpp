#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 1e4+5;
int a[N];
ll f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    int ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    for(int l = 1; l <= n;++l){
        for(int r = l; r<= n; ++r){
            if(f[r]-f[l-1] == k) ans++;
           // cerr << "l: " << l << " r: " << r << " ans: " << ans << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
}