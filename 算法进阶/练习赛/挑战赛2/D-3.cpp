#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string st;
        cin >> st;
        int x = 0, y = 0;
        for(int i = 0; i < n; ++i){
            if(st[i] == '0') x++;
            else y++;
        }
        int ans = min(x, y);
        int l = 0, r = 0;
        for(int i = 0; i < n; ++i){
            ans = min(ans, r+x-l);
            if(i < n){
                if(st[i] == '1') r++;
                else l++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}