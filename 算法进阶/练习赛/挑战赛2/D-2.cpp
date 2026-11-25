#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int T;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string st;
        cin >> st;
        int x = 0, y = 0;
        for(int i = 0; i < n; ++i){
            if(st[i] == '0') x++;
            if(st[i] == '1') y++;
        }
        int ans = min(x,y);
        int ansl = 0;
        int ansr = 0;
        int l = 0, r = 0;
        for(int i = 0; i < n; ++i){
            if(st[i] == '1'){
                l = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i){
            if(st[i] == '0'){
                r = i;
                break;
            }
        }
        for(int i = l; i < n; ++i){
            if(st[i] == '0') ansl++;
        }
        for(int i = r; i >= 0; --i){
            if(st[i] == '1') ansr++;
        }
        // cout << ansl << " " << ansr << " ";
        ansl = min(ansl,ansr);
        ans = min(ans,ansl);
        cout << ans << "\n";
    }
    
    

    return 0;
}