#include <iostream>
using namespace std;

void find_solution(int p) {
    // 题目要求 q 可以很大，但我们为了找规律，先在小范围内试
    for (long long q = 2; q <= 1000; q++) { 
        for (long long x2 = 1; x2 < p; x2++) {
            // 验证第二个条件：x2^2 ≡ q (mod p)
            if ((x2 * x2) % p == q % p) {
                
                for (long long x1 = 1; x1 < q; x1++) {
                    // 验证第一个条件：x1^2 ≡ p (mod q)
                    if ((x1 * x1) % q == p % q && x2 == 1) {
                        cout << "p=" << p << " -> x1=" << x1 
                             << ", x2=" << x2 << ", q=" << q << endl;
                        // 找到几个就够了，不用全找完
                    }
                }
            }
        }
    }
}

int main() {
    find_solution(5);
    return 0;
}