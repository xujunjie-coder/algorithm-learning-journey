#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    const int N = 12;
    const ll INF = (1LL << 60);

    ll three[N + 1] = {};
    ll four[N + 1] = {};

    // 三柱汉诺塔
    three[0] = 0;
    for (int n = 1; n <= N; ++n) {
        three[n] = 2 * three[n - 1] + 1;
    }

    // 四柱汉诺塔
    four[0] = 0;

    for (int n = 1; n <= N; ++n) {
        four[n] = INF;

        for (int k = 1; k <= n; ++k) {
            ll cost = 2 * four[n - k] + three[k];
            four[n] = min(four[n], cost);
        }

        cout << four[n] << '\n';
    }

    return 0;
}