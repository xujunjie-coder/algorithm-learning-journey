#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vii;
typedef __int128_t i128;
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define rep(i,n) for(ll i = 1; i <= n; i++)
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
ll h[MAX];
ll S[MAX];
ll f[MAX];
ll w[MAX];
ll ans[MAX];
struct node
{
    ll to;
    ll w;
};

void dfs1(ll u,vector<vector<node>>& s)
{
    S[u] = h[u];

    for(auto & [v,t] : s[u])
    {
        dfs1(v,s);

        if(t <= h[u])
        {
            S[u] += S[v];
        }
    }
}


void dfs2(ll u,ll out,vector<vector<node>>& s)
{
    ans[u] = (S[u] + out);

    ll cur_out = out;

    for(auto & [v,w] : s[u])
    {
        dfs2(v,cur_out + w,s);

        cur_out += S[v];
    }
}
void so()
{
    int n;cin >> n;
    vector<vector<node>> gr(n + 1,vector<node>());
    rep(i,n)
    {
        cin >> h[i];
    }
    rep(i,n - 1)
    {
        cin >> f[i];
    }
    rep(i,n - 1)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n - 1; i++)
    {
        gr[f[i]].pb({i + 1,w[i]});
    }
    for(int i = 1; i <= n; i++)
    {
        sort(all(gr[i]),[&](node& a,node& b) -> bool
    {
        return a.w < b.w;
    });
    }

    dfs1(1,gr);


    dfs2(1,0,gr);
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--){             
    so();           
    }             
    return 0;
}