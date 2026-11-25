#ifndef OI_SQUARE_ROOT_SIMPLIFICATION_TEMPLATE
#define OI_SQUARE_ROOT_SIMPLIFICATION_TEMPLATE

#include <utility>

// Contract: n >= 0; type: signed long long. No interval semantics/dependencies.
// Returns {outside, inside}: original_n = outside^2 * inside.
// For n > 0: outside >= 1; inside >= 1 is square-free.
// For n == 0: returns {0, 1}; inside == 1 means the root is an integer.
// Worst-case time: O(sqrt(original_n)); extra space: O(1).
// Large primes near LLONG_MAX are too slow for trial division.
// p <= n/p avoids overflow; products in verification must also avoid overflow.
// Origin: quadratic-larger-root; verification evidence is in reviews/.
std::pair<long long, long long> simplifySqrt(long long n) {
    if (n == 0) return {0, 1};

    long long inside = 1, outside = 1;
    for (long long p = 2; p <= n / p; ++p) {
        int cot = 0;
        while (n % p == 0) {
            n /= p;
            ++cot;
        }
        for (int i = 1; i <= cot / 2; ++i) {
            outside *= p;
        }
        if (cot % 2 == 1) inside *= p;
    }
    if (n > 1) inside *= n;
    return {outside, inside};
}

#endif
