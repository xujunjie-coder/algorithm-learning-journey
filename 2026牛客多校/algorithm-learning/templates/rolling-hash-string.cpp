#include <string>
#include <vector>

using namespace std;

// Contract: 0-based, closed interval [left, right].
// get(left, right) returns the 64-bit polynomial hash of that substring.
// BASE and unsigned overflow are part of the hash contract.
// Complexity: construction O(n), query O(1), memory O(n).
// This is a probabilistic equality test; collisions are theoretically possible.
struct RollingHash {
    using ull = unsigned long long;
    static constexpr ull BASE = 1331;

    vector<ull> hash_value;
    vector<ull> power;

    explicit RollingHash(const string& text)
        : hash_value(text.size() + 1), power(text.size() + 1) {
        power[0] = 1;

        for (int i = 0; i < static_cast<int>(text.size()); ++i) {
            hash_value[i + 1] = hash_value[i] * BASE
                              + static_cast<unsigned>(text[i] - 'a' + 1);
            power[i + 1] = power[i] * BASE;
        }
    }

    ull get(int left, int right) const {
        return hash_value[right + 1]
             - hash_value[left] * power[right - left + 1];
    }
};
