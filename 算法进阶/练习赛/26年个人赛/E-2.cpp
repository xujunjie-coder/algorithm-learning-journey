#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<int> s;
    for (int i = 0; i < 2 * n + 2; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (auto it = s.begin(); it != s.end(); ++it) {
        if (s.count(*it) == 1) {
            cout << *it << ' ';
        }
    }
    cout << '\n';
}