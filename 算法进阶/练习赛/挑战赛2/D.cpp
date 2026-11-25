#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int T;
// int const N = 2e5+5;
// int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') x++;
            if(s[i] == '1') y++;
        }
        int ans = min(x,y);
        int anss = 0;
        if(n % 2 == 0){
            int mid = n/2-1;
            for(int i = 0; i < n; ++i){
                if(i <= mid){
                    if(s[i] == '1') anss++; 
                }
                if(i > mid){
                    if(s[i] == '0') anss++;
                }
            }
        }else{
            int mid = n/2;
            for(int i = 0; i < n; ++i){
                if(i == mid) continue;
                if(i < mid){
                    if(s[i] == '1') anss++; 
                }
                if(i > mid){
                    if(s[i] == '0') anss++;
                }
            }
        }
        ans = min(ans,anss);
        cout << ans << "\n";
    }
    

    return 0;
}