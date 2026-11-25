#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int n;
int const N = 1e5 + 5;
ll a[N];
ll diff[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> a[1];
    diff[1] = a[1];
    ll x = 0, y = 0;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
        if (diff[i] > 0) x += diff[i];
        else y += (-diff[i]);
    }

    ll ans1 = max(x, y);
    ll ans2 = abs(x - y) + 1;
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}

