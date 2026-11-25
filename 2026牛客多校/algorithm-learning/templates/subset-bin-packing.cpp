// Contract: 1 <= n <= 18, weights c[0..n), 1 <= c[j] <= w <= 1e8.
// dp[mask] = {cars, remaining capacity of last car}; minimize cars,
// then maximize remaining capacity. Prints minimum cars for full mask.
// Time O(n*2^n). Logical states O(2^n); this fixed array allocates O(2^N).
// int is sufficient under these bounds; masks require n < int bit width.
// Origin: kitten-cable-car; local tests, no reported online AC.
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, w, c[N];
pair<int, int> dp[1 << N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 0; i < n; ++i) cin >> c[i];
    int tot = 1 << n;

    // [旧错 1] Global {0,0} is not an unreachable state.
    for (int i = 0; i < tot; ++i) dp[i] = {n + 1, 0};
    dp[0] = {1, w};

    for (int i = 0; i < tot; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) continue;
            // [旧错 4] Mutate the copy to build a candidate, not dp[i].
            auto nxt = dp[i];
            if (nxt.second >= c[j]) { // [旧错 2] Exact fit is legal.
                nxt.second -= c[j]; // [旧错 3] Subtract from OLD remainder.
            } else {
                ++nxt.first;
                nxt.second = w - c[j];
            }
            int mask = i | (1 << j);
            // [旧错 5] Several paths reach mask; don't overwrite blindly.
            // [旧错 6] Equality is ==; [旧错 7] More remainder is better.
            if (dp[mask].first > nxt.first ||
                (dp[mask].first == nxt.first && dp[mask].second < nxt.second)) {
                dp[mask] = nxt;
            }
        }
    }
    cout << dp[tot - 1].first << '\n'; // Full mask, not number of states.
}
