#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 5e5+5;
int a[N];
ll s[N];
int T, n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(cin >> n && n){
        unordered_map<ll,int> mp;
        for(int i = 1; i <= n; ++i){ 
            cin >> a[i];
            s[i] = s[i-1] + a[i];
        }
        ll ans=0;
        mp[s[0]] = 1;
        for (int i = 1; i <= n; i++) {
            ans += mp[s[i] - i];
            mp[s[i] - i]++;
        }
        std::cout<<ans<<"\n";

    }
    

    return 0;
}