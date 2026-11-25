#include <functional>

using namespace std;

// Contract: check(x) is false...false,true...true.
// Returns the first x in [left, right] for which check(x) is true.
// Requires at least one feasible value in the interval.
template <class Check>
long long first_true(long long left, long long right, Check check) {
    while (left < right) {
        long long middle = left + (right - left) / 2;

        if (check(middle)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}

// Contract: check(x) is true...true,false...false.
// Returns the last x in [left, right] for which check(x) is true.
// Requires at least one feasible value in the interval.
template <class Check>
long long last_true(long long left, long long right, Check check) {
    while (left < right) {
        long long middle = left + (right - left + 1) / 2;

        if (check(middle)) {
            left = middle;
        } else {
            right = middle - 1;
        }
    }
    return left;
}
