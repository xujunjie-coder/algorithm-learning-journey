#include <cstdint>

using int64 = long long;

// Requires: mod_pow(base, exponent, mod) from modular-fast-power.cpp.
// Contract: mod > 1, exponent >= 0.
// Returns (1 + base + base^2 + ... + base^exponent) mod mod.
// Complexity: O(log^2 exponent) with the supplied binary exponentiation helper.
// Numeric assumptions: intermediate products fit in signed 64-bit integer.
// Originating problem: sum-divisors-power-mod-9901.
int64 geometric_sum_mod(int64 base, int64 exponent, int64 mod) {
    base %= mod;

    if (exponent == 0) {
        return 1 % mod;
    }

    if (exponent % 2 == 0) {
        int64 half = exponent / 2;
        int64 middle_power = mod_pow(base, half, mod);
        int64 left_sum = geometric_sum_mod(base, half - 1, mod);

        return ((middle_power + 1) % mod * left_sum
                + mod_pow(base, exponent, mod)) % mod;
    }

    int64 half = exponent / 2;
    int64 right_power = mod_pow(base, half + 1, mod);
    int64 half_sum = geometric_sum_mod(base, half, mod);

    return (right_power + 1) % mod * half_sum % mod;
}
