#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 2e5 + 10;

int T;
int a[N];


int check(int x, int y, int n) {
    vector<int> have(n, 0);

    while (x >= 0 && y < 2 * n && a[x] == a[y]) {
        have[a[x]] = 1;
        x--;
        y++;
    }

    int mex = 0;

    while (mex < n && have[mex]) {
        mex++;
    }

    return mex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int l = -1;
        int r = -1;

        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];

            if (a[i] == 0) {
                if (l == -1) {
                    l = i;
                } else {
                    r = i;
                }
            }
        }

        int ans = 1;

        ans = max(ans, check(l, l, n));

        ans = max(ans, check(r, r, n));

        ans = max(ans, check((l + r) / 2,(l + r + 1) / 2,n));

        cout << ans << endl;
    }

    return 0;
}