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
    ll n,k;
    ll ans;
    cin >> n >> k;
    ans = abs(k);
    for(int i = 0; i < n; ++i){
        ll x,y;
        cin >> x >> y;
        ans = min(abs(0-x)+abs(k-y),ans);
    }
    cout << ans;
    

    return 0;
}