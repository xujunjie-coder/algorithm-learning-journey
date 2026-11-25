// Contract: enumerate every combination containing exactly m numbers from [1, n].
// Interval semantics: cur is the next number to decide; the candidate range is [1, n].
// Learner supplies: n, m, and the output format if needed.
// Return meaning: dfs returns after processing or pruning the current decision tree.
// Complexity: O(2^n + m * C(n, m)) in the worst case; O(n) auxiliary space.
// Numeric assumptions: n and m fit in int; a.size() is compared with m after promotion.
// Originating problem: recursive-combination-enumeration (AC reported by learner).

#include <iostream>
#include <vector>

using namespace std;

vector<int> chosen;
int n, m;

void dfs(int cur) {
    if (cur > n) {
        if (static_cast<int>(chosen.size()) == m) {
            for (int x : chosen) {
                cout << x << ' ';
            }
            cout << '\n';
        }
        return;
    }

    // Prune impossible states.
    if (static_cast<int>(chosen.size()) > m ||
        static_cast<int>(chosen.size()) + (n - cur + 1) < m) {
        return;
    }

    // Choose cur.
    chosen.push_back(cur);
    dfs(cur + 1);
    chosen.pop_back();

    // Do not choose cur.
    dfs(cur + 1);
}
