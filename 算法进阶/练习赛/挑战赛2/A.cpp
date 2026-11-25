#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        if(n%k == 0) cout << 0 << "\n";
        else{
            cout << k-n%k << "\n";
        }
        
    }
    

    return 0;
}