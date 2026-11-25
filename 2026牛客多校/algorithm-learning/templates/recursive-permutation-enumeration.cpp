// Contract: enumerate every permutation of the numbers in [1, n].
// Interval semantics: cur is the position currently being filled; positions are [1, n].
// Learner supplies: n; global arrays are zero-initialized before dfs(1).
// Return meaning: dfs returns after enumerating all permutations under the current prefix.
// Complexity: O(n * n!) including output; O(n) auxiliary space.
// Numeric assumptions: 1 <= n <= MAXN; used values are indexed by [1, n].
// Originating problem: recursive-permutation-enumeration (corrected code; AC not reported).

#include <iostream>

using namespace std;

const int MAXN = 15;
int permutation[MAXN + 1];
int used[MAXN + 1];
int n;

void dfs(int cur) {
    if (cur > n) {
        for (int i = 1; i <= n; ++i) {
            cout << permutation[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int value = 1; value <= n; ++value) {
        if (used[value]) continue;

        permutation[cur] = value;
        used[value] = 1;

        dfs(cur + 1);

        // Undo only the current choice; the loop tries the next value.
        used[value] = 0;
    }
}
