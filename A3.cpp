#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve () {
    int n;cin >> n;
    vector<long long> a(n+1);
    for (int i=1;i<=n;++i) {cin >> a[i];}
    vector<long long,vector<long long>> dp(n,vector<long long>());
    long long ans=0;
    for (int l=1;l<=n;++l) {
        ans+=dp[l-1][l-a[l]];
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;cin >> T;
    while(T--) solve();
    return 0;
}