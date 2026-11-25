#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

const int N = 1000010;

string st;
int n;
int kase;

ull f[N], rf[N], p[N];

void get_hash(const string& s) {
    f[0] = 0;
    rf[0] = 0;
    p[0] = 1;

    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * 1331 + (s[i] - 'a' + 1);
        p[i] = p[i - 1] * 1331;
    }

    string rs = s;
    reverse(rs.begin() + 1, rs.end());

    for (int i = 1; i <= n; ++i) {
        rf[i] = rf[i - 1] * 1331 + (rs[i] - 'a' + 1);
    }
}

ull sub_hash(const ull h[], int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool is_palindrome(int l, int r) {
    int rl = n - r + 1;
    int rr = n - l + 1;

    return sub_hash(f, l, r) == sub_hash(rf, rl, rr);
}

// k 表示奇数回文半径，回文长度为 2 * k + 1
bool check_odd(int k) {
    for (int center = k + 1; center <= n - k; ++center) {
        if (is_palindrome(center - k, center + k)) {
            return true;
        }
    }

    return false;
}

// k 表示偶数回文半长度，回文长度为 2 * k
bool check_even(int k) {
    if (k == 0) {
        return true;
    }

    for (int center = k; center + k <= n; ++center) {
        int l = center - k + 1;
        int r = center + k;

        if (is_palindrome(l, r)) {
            return true;
        }
    }

    return false;
}

int binary_search(bool odd) {
    int l = 0;
    int r = odd ? (n - 1) / 2 : n / 2;

    while (l < r) {
        int mid = l + (r - l + 1) / 2;

        bool possible;

        if (odd) {
            possible = check_odd(mid);
        } else {
            possible = check_even(mid);
        }

        if (possible) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    if (odd) {
        return 2 * l + 1;
    } else {
        return 2 * l;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> st && st != "END") {
        n = st.length();
        st = " " + st;

        get_hash(st);

        int odd_answer = binary_search(true);
        int even_answer = binary_search(false);

        int answer = max(odd_answer, even_answer);

        cout << "Case " << ++kase << ": " << answer << '\n';
    }

    return 0;
}