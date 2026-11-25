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
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'


int T,n,h,o;
pair<ll,ll> calc(int n, int m){ //N级别城市的M地位置
    if(n == 0){
        return make_pair(0,0);
    }
    ll cnt =  1LL << (2 * (n - 1)); 
    pair<ll,ll> pos = calc(n-1,m % cnt);
    ll x = pos.first, y = pos.second;
    ll z = m / cnt;
    ll len = 1LL << (n - 1);
    if(z == 0) return make_pair(y,x);
    if(z == 1) return make_pair(x, y+ len);
    if(z == 2) return make_pair(x + len, y + len);
    if(z == 3) return make_pair(2 * len - y - 1, len - x - 1);
    return make_pair(-1,-1);
}
ll dist(pair<ll,ll> a, pair<ll,ll> b){
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return round(10LL * sqrt(dx * dx + dy * dy));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> h >> o;
        h--;o--;    //下标从0开始
        cout << dist(calc(n,h),calc(n,o)) << "\n";
    }
    

    return 0;
}