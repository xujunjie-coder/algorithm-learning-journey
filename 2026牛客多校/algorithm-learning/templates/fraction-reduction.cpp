#ifndef OI_FRACTION_REDUCTION_TEMPLATE
#define OI_FRACTION_REDUCTION_TEMPLATE

#include <utility>
#include "gcd-euclidean.cpp"

// Contract: mu != 0; zi and mu must not equal LLONG_MIN.
// No interval semantics; dependency: gcd-euclidean.cpp in the same directory.
// Returns {numerator, denominator}, denominator > 0 and gcd = 1.
// Zero is normalized to {0, 1}; denominator 1 means an integer.
// Time: O(log(min(|zi|, |mu|) + 1)); extra space: O(1).
// Origin: quadratic-larger-root; verification evidence is in reviews/.
std::pair<long long, long long> huajian(long long zi, long long mu) {
    if (mu < 0) {
        zi = -zi;
        mu = -mu;
    }
    long long g = gcdll(zi, mu);
    return {zi / g, mu / g};
}

// Usage:
// auto p = huajian(zi, mu);
// cout << p.first;
// if (p.second != 1) cout << '/' << p.second;

#endif
