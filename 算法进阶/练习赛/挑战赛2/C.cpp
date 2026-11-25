#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int T;
int const N = 2e5+5;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ll tot = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            tot+=a[i];
        }
        int maxx = 0;
        for(int i = 0; i < n-1; ++i) {
            maxx = max(maxx,(a[i] + a[i+1]));
        }
        cout << tot-maxx << "\n";
    }
    

    return 0;
}