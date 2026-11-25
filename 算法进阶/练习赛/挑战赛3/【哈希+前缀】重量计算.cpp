#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
unordered_map<ll,int> mp;
int const N = 1e4+5;
int a[N];
ll f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    int ans = 0;
    cin >> n >> k;
    mp[0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
        ans+=mp[f[i]-k];
        mp[f[i]]++;
    }
    cout << ans << "\n";
    return 0;
}