#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 2e5+5;
int n,m,a,b,s,t;
vector<vector<int>> g;
queue<int> q;
int da[N];  
int db[N];
int diff[N];
void bfs(int x,int d[]){
    fill(d,d + n + 2,-1);
    q.push(x);
    d[x] = 0;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto v : g[x]){
            if(d[v] == -1){
                d[v] = d[x]+1;
                q.push(v);
            }
        }
    }
}

int dist[N];
bool v[N];
priority_queue<pair<int,int>> pq;   //{权值，节点}
void dijsktra(int start){
    memset(dist,0x3f,sizeof dist);
    memset(v,0,sizeof v);
    dist[start] = diff[start];
    pq.push({-dist[start],start});
    while(pq.size()){
        int val = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(v[x]) continue;
        v[x] = 1;
        for(int y : g[x]){
            int nd = max(dist[x],diff[y]);//取该路径的最大值
            if (nd < dist[y]) {
                dist[y] = nd;
                pq.push({-dist[y], y});
            }
        }
    }
}   


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> a >> b >> s >> t;
    g.resize(n + 1);
    while(m--){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(a,da);
    bfs(b,db);
    for(int i = 1; i <= n; ++i){
        diff[i] = abs(da[i] - db[i]);
    }
    dijsktra(s);
    cout << dist[t] << "\n";
    return 0;
}