// Contract: 1 <= n <= 18; cats c[1..n], 1 <= c[i] <= w <= 1e8.
// dfs(cur,cnt): cats [1,cur) assigned; cars [1,cnt] opened.
// sheng[i] is remaining capacity; unopened cars stay w after backtracking.
// Prints minimum number of identical cars. New car is one branch outside loop.
// Worst case exponential search; conservative time O(n*(n+1)^n), space O(n).
// Bounds fit int here. Origin: kitten-cable-car, locally verified, no online AC.
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, w, c[N], sheng[N], ans;

void dfs(int cur, int cnt) {
    if (cnt >= ans) return;  // car count cannot decrease in descendants
    if (cur == n + 1) {
        ans = cnt;
        return;
    }
    for (int i = 1; i <= cnt; ++i) {
        if (sheng[i] >= c[cur]) {
            sheng[i] -= c[cur];
            dfs(cur + 1, cnt);
            sheng[i] += c[cur];
        }
    }
    sheng[cnt + 1] -= c[cur];
    dfs(cur + 1, cnt + 1);
    sheng[cnt + 1] += c[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    fill(sheng, sheng + N, w);
    sort(c + 1, c + n + 1, greater<int>());
    ans = n;  // known feasible upper bound: one cat per car
    dfs(1, 1);
    cout << ans << '\n';
}
