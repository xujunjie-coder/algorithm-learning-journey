#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

ll a,b,p;
ll res;
ll solve(){
    a %= p;
    while(b > 0){
        if(b & 1){
        res = (res + a) % p;
    }
    a = a * 2 % p;
    b >>= 1;
}
return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> p;
    cout << solve() << "\n";
    return 0;
}