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
long long rem(long long x) {
    return ((x % 5) + 5) % 5;
}
int const N = 2e5+5;
ll a[N];
ll dif[N];
int n,q;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n-1; ++i){
        dif[i] = a[i+1]-a[i];   //存原始差分数组
    }
    for(int i = 1; i <= n-1; ++i){
        ans = ans + rem(dif[i]);
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        int x,y;
        if(l-1>= 1 && r+1 <= n){
            x = rem(dif[l-1]) + rem(dif[r]);
            dif[l-1]++;dif[r]--;
            y = rem(dif[l-1]) + rem(dif[r]);
        }else if(l-1 < 1 && r+1 <= n ){
            x = rem(dif[r]);
            dif[r]--;
            y = rem(dif[r]);
        }else if(l-1>= 1 && r+1 > n){
            x = rem(dif[l-1]);
            dif[l-1]++;
            y = rem(dif[l-1]);
        }
        ans = ans + y - x;
        cout << ans << "\n";
    }
    
    return 0;
}