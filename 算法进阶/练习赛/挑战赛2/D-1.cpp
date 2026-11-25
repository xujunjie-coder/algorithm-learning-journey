#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int T;
int const N =2e5+5;
int s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
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
        int anss = 0;
        s[0] = (st[0] - '0');
        for(int i = 1; i < n; ++i){
            s[i] = s[i-1] + (st[i] - '0');
        }
        int mid = 0;
        for(int i = 0; i < n-1; ++i){
            if((i - s[i]) == ((i+1) - s[i+1])){
                mid = i;
                // cout <<  "mid: "<< mid << "\n";
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(i <= mid && st[i] == '1') anss ++;
            if(i > mid && st[i] == '0') anss ++;
        }
        ans = min(anss,ans);
        cout << ans << "\n";
    }

    return 0;
}