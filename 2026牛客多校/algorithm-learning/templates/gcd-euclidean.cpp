#ifndef OI_GCD_EUCLIDEAN_TEMPLATE
#define OI_GCD_EUCLIDEAN_TEMPLATE

// Contract: signed long long inputs; neither input may equal LLONG_MIN.
// No interval semantics or learner-supplied function is required.
// Returns gcd(|a|, |b|) >= 0; gcd(0, 0) is defined as 0 here.
// Time: O(log(min(|a|, |b|) + 1)); extra space: O(1).
// Origin: quadratic-larger-root; verification evidence is in reviews/.
long long gcdll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

#endif
