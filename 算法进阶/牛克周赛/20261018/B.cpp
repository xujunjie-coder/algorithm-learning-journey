#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,k;
    cin >> a >> b >> k;
    int jin = a/b;
    int sheng = a%b;
    int shift = 1;
    for(int i = 0; i < k; ++i){
        shift *= 10;
    }
    int yin = sheng * shift / b;
    cout << jin << " " << yin << '\n';
    return 0;
}