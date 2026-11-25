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
int T;
void solve(ll a){
    ll i = ceil(sqrt(a));
        for(; i > 0; --i){
            if(a % i == 0){
                cout << i << " " << a/i << "\n";
                return;
            }
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        int x,y;
        cin >> x >> y;
        ll a = x*y;
        solve(a);
    }

    return 0;
}