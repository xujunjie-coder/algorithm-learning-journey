#include <cstdint>
#include <utility>
#include <vector>

using int64 = long long;

// Contract: value >= 1.
// Returns distinct prime factors and their positive exponents in ascending order.
// For value == 1, returns an empty vector.
// Complexity: O(sqrt(value)) worst-case time and O(number of distinct factors) space.
// Originating problem: sum-divisors-power-mod-9901.
std::vector<std::pair<int64, int>> prime_factorization(int64 value) {
    std::vector<std::pair<int64, int>> factors;

    for (int64 prime = 2; prime <= value / prime; ++prime) {
        if (value % prime != 0) {
            continue;
        }

        int exponent = 0;
        while (value % prime == 0) {
            value /= prime;
            ++exponent;
        }

        factors.emplace_back(prime, exponent);
    }

    if (value > 1) {
        factors.emplace_back(value, 1);
    }

    return factors;
}
