#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

     int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        if(n == 1){
            cout << a[0] << "\n";
            continue;
        }
        ll ans = 1LL << 62;
        for(int t = 0; t < 2; ++t){
            ll s = a[0];
            for(int i = 1; i < n; ++i){
                ll w = a[i-1] + a[i];
                ll v = 2*s + a[i] + 1LL*(n-1-i)*w;
                ans = min(ans, v);
                s += a[i];
            }
            reverse(a.begin() + 1, a.end());
        }
        cout << ans << "\n";
    }


    return 0;
}