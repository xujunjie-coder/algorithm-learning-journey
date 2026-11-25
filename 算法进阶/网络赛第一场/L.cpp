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

const int N = 500005;
int tr[N][26], cnt[N], f[N], tot;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        ans += i;
        int u = 0, d = 0;
        for(auto c : s){
            int x = c - 'a';
            if(!tr[u][x]) tr[u][x] = ++tot;
            u = tr[u][x];
            ++d;
            int k = ++cnt[u];
            if(f[k] < d){
                ans += (d^k) - (f[k]^k);
                f[k] = d;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}