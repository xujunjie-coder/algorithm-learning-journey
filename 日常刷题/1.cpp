#include <iostream>
using namespace std;
int count_factors(int n) {
	if (n == 1) return 1; 
	int count = 1;
	for (int i = 2; i*i<=n; ++i) { 
		if (n % i == 0) {
			int exponent = 0;
			while (n % i == 0) { 
				++exponent;
				 n /= i;
			}
			count = (exponent + 1) * count; 
		}
	}
	if (n > 1) count *= 2; 
	return count;
}
int main() {
	int n;
	cin >> n;
	
	if (n <= 0) {
		return 1;
	}
	
	cout  << count_factors(n) << endl;
	return 0;
}
