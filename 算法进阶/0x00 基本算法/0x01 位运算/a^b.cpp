#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
ll a,b,p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> p;
    ll res = 1 % p;
    a %= p;
    while(b > 0){
        if(b & 1){
            res = res * a % p;
        }
        a = a * a % p;  //防止a*a，int溢出这里直接开ll
        b >>= 1;
    }
    cout << res << "\n";
    return 0;
}