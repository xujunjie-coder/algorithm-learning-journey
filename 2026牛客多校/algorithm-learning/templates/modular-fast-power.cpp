#include <cstdint>

using int64 = long long;

// Contract: mod > 1, exponent >= 0.
// Returns (base^exponent) mod mod.
// Complexity: O(log exponent) time and O(1) auxiliary space.
// Numeric assumptions: intermediate products fit in signed 64-bit integer.
// Originating problem: sum-divisors-power-mod-9901.
int64 mod_pow(int64 base, int64 exponent, int64 mod) {
    int64 result = 1 % mod;
    base %= mod;

    while (exponent > 0) {
        if (exponent & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exponent >>= 1;
    }

    return result;
}
