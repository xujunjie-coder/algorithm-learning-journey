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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') ans++;
        }
        if(ans % 2 == 0){
            cout << ans/2 << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    

    return 0;
}