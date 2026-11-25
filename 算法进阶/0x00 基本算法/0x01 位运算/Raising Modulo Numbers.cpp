#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll qpow(ll a, ll b, ll p){
    ll res = 1 % p;
    a %= p;
    while(b > 0){
        if(b & 1){
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;
    while(z--){
        int m, h;
        cin >> m >> h;

        ll ans = 0;
        for(int i = 1; i <= h; ++i){
            ll a, b;
            cin >> a >> b;
            ans = (ans + qpow(a, b, m)) % m;
        }

        cout << ans << '\n';
    }

    return 0;
}