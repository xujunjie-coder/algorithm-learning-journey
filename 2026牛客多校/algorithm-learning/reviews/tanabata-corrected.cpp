// 按对话修正版重建；用户于 2026-10-30 确认修改后 AC，未另贴最终提交源码。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, m, t;
int ro[N], co[N];
ll f[N];

ll solve(int a[], int len) {
    int avg = t / len;
    f[0] = 0;
    for (int i = 1; i <= len; ++i)
        f[i] = f[i - 1] + a[i] - avg;
    sort(f + 1, f + len + 1);
    ll median = f[1 + len / 2];
    ll ans = 0;
    for (int i = 1; i <= len; ++i)
        ans += abs(f[i] - median);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t;
    for (int i = 1; i <= t; ++i) {
        int x, y;
        cin >> x >> y;
        ++ro[x];
        ++co[y];
    }
    // 旧错1：bool row, col = 0 只初始化了 col。
    bool row = (t % n == 0);
    bool col = (t % m == 0);
    // 旧错3：solve 返回值、累加器、接收答案的变量都应使用 long long。
    ll ans1 = 0, ans2 = 0;
    if (row) ans1 = solve(ro, n);
    if (col) ans2 = solve(co, m);
    if (row && col) {
        // 旧错2：both 要加上行、列两个方向的最少交换次数。
        cout << "both " << ans1 + ans2 << '\n';
    } else if (row) {
        cout << "row " << ans1 << '\n';
    } else if (col) {
        cout << "column " << ans2 << '\n';
    } else {
        cout << "impossible\n";
    }
}
