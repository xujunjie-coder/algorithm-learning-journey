#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 510;
int n;
int a[N];
ll ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= 1000; ++i){
        ll t = 0;
        for(int j = 1; j <= n; ++j){
            if(a[j] % i == 0){
                t += a[j];
            }
        }
        t *= i;
        ans = max(ans,t);
    }
    cout << ans << "\n";
    return 0;
}