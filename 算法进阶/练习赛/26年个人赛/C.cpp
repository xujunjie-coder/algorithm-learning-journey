#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const p = 1e9+7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int askc(int x,int y){
    cout << "> " << x << " " << y << endl;
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}

int askv(int x){
    cout << "? " << x << endl;
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int mn = 1, mx = 1;
    for (int i = 2; i <= n; ++i) {
        if (askc(mn, i)) mn = i;
        if (askc(i, mx)) mx = i;
    }

    ll amin = askv(mn);
    ll amax = askv(mx);

    ll delta = (amax - amin + p) % p;
    ll d = delta * qpow(n - 1, p - 2) % p;

    cout << "! " << d << endl;

    return 0;
}