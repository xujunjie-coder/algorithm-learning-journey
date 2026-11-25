#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const MOD = 998244353;
int const N = 1e6+5;
int n;
ll a[N];
ll b[N];
ll f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) f[i] = (f[i-1] + b[i])%MOD;

    ll E = 0;
    for(int i = 1; i < n; ++i){
        ll x = a[i]-a[i+1];
        ll s_b = f[i];
        E = (E % MOD + s_b * x % MOD) % MOD;
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            ll x,v;
            cin >> x >> v;
            a[x] = (a[x] + v)%MOD;
            if(x == n){
                E = (E - (f[x-1] * v) % MOD)%MOD;
            }else{
                E = ((v * b[x])%MOD + E)%MOD;
            }
            
        }else if(t == 2){
            ll x,v;
            cin >> x >> v;
            b[x] = (b[x]+v)%MOD;
            if(x < n){
                f[n - 1] = (f[n - 1] + v) % MOD;
            }
            E =  (E % MOD + (v%MOD*(a[x]-a[n])%MOD)%MOD)%MOD;
        }else{
            ll v;
            cin >> v;
            ll ans = (E+v)%MOD;
            if(ans < 0){
                ans += MOD;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}