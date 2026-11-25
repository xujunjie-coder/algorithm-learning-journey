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
int const N = 2e5+5;
vector<ll> vec1;
vector<ll> vec2;
ll a[N],b[N];
ll pre1[N];
ll pre2[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x,y,s,m,k;
    cin >> x >> y >> s >> m >> k;
    ll n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        if(!b[i]) vec1.push_back(a[i]);
        else vec2.push_back(a[i]);
    }
    sort(vec1.begin(),vec1.end(),greater<ll>());
    sort(vec2.begin(), vec2.end(), greater<ll>());

    ll len1 = vec1.size();
    ll len2 = vec2.size();
    for(int i = 0; i < len1; ++i){
        pre1[i+1] = pre1[i] + vec1[i];
    }
    for(int i = 0; i < len2; ++i){
        pre2[i+1] = pre2[i] + vec2[i];
    }
    
    ll money1 = k*x;
    ll money2 = k*x+y;
    ll ren_max = m / k;
    ll maxI = min({len2, ren_max, s / money2});
    ll ans = 0;

    for (ll i = 0; i <= maxI; ++i) {
        ll sheng_money = s - i * money2;
        ll sheng_tao = sheng_money / money1;
        ll sheng_ren = ren_max - i;
        ll j = min({len1, sheng_tao, sheng_ren});

        ans = max(ans, pre2[i] + pre1[j]);
    }

    cout << ans << '\n';
    return 0;
}