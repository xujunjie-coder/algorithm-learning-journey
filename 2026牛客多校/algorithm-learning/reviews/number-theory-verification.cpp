#include <iostream>
#include <string>
#include "fraction-reduction.cpp"
#include "square-root-simplification.cpp"

int main() {
    std::string operation;
    long long a, b;
    while (std::cin >> operation >> a) {
        if (operation == "gcd") {
            std::cin >> b;
            std::cout << gcdll(a, b) << '\n';
        } else if (operation == "fraction") {
            std::cin >> b;
            auto p = huajian(a, b);
            std::cout << p.first << ' ' << p.second << '\n';
        } else if (operation == "sqrt") {
            auto p = simplifySqrt(a);
            std::cout << p.first << ' ' << p.second << '\n';
        } else {
            return 2;
        }
    }
}
