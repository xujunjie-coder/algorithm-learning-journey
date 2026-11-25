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

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n + 1);
        vector<int> deg(n + 1), ans(n + 1);

        for(int i = 0; i < m; ++i){
            int l, r, u;
            cin >> l >> r >> u;
            for(int j = l; j < r; ++j){
                int v;
                cin >> v;
                g[u].push_back(v);
                ++deg[v];
                u = v;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i <= n; ++i){
            if(!deg[i]) pq.push(i);
        }

        int cnt = 0;
        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            ans[u] = ++cnt;

            for(int v : g[u]){
                if(--deg[v] == 0) pq.push(v);
            }
        }
        if(cnt != n){
            cout << -1 << "\n";
        }else{
            for(int i = 1; i <= n; ++i){
                cout << ans[i] << ' ';
            }
            cout << "\n";
        }
    }
    
    return 0;
}