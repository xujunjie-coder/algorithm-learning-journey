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
#include <unordered_map>
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
        vector<int> a(n), cnt(n + 1);
        unordered_map<int, int> mp, res;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            ++mp[a[i]];
            if(a[i] <= n) ++cnt[a[i]];
        }
        int mex = 0;
        while(mex < n && cnt[mex]) ++mex;
        for(int x : a){
            int k = mex + x;
            if(res.count(k)) continue;
            int v = mex;
            while(v < n){
                int y = k - v;
                int c = cnt[v];
                if(y != v){
                    auto it = mp.find(y);
                    if(it != mp.end()) c += it->second;
                }
                int need = (y >= 0 && y < v) ? 2 : 1;
                if(c < need) break;
                ++v;
            }
            res[k] = v;
        }
        int q;
        cin >> q;
        int ans = 0;
        for(int i = 0; i < q; ++i){
            int k;
            cin >> k;
            auto it = res.find(k);
            if(it == res.end()){
                ans ^= mex;
            }else{
                ans ^= it->second;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}