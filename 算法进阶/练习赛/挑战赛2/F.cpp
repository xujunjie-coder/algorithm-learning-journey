#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int T;
int const N = 2e5+5, M = 4e5+5;
int const INF = 0x3f3f3f3f;
int head[N],ver[M],nxt[M],edge[M];
bool v[N][2];   //这里没有区分颜色
int d[N][2];    //d[i][j] = {节点编号，红绿}的最短时间
priority_queue<pair<int,pair<int,int>>> pq;   //{时间，{节点，颜色}}
void dijkstra(int flag){   //分为0/1起点,进行两次
    memset(d,0x3f,sizeof d);
    memset(v,0,sizeof v);
    d[1][flag] = 0;
    pq.push({0,{1,flag}});
    while(pq.size()){
        int x = pq.top().second.first;
        int f = pq.top().second.second;
        pq.pop();
        if(v[x][f]) continue;
        v[x][f] = 1;
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i], z = edge[i];
            if((!z) == f && d[y][z] > d[x][f] + 1){
                d[y][z] = d[x][f] + 1;
                pq.push({-d[y][z],{y,z}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        memset(head, 0, sizeof(head));  //这里
        int n,m;
        int tot = 0;
        cin >> n >> m;
        
        for(int i = 0; i < m; ++i){
            int x,y,z;
            cin >> x >> y >> z;
            auto add = [&](int x,int y,int z,int& tot){
                ver[++tot] = y, edge[tot] = z;
                nxt[tot] = head[x],head[x] = tot;
            };
            add(x,y,z,tot);
            add(y,x,z,tot);
        }
        dijkstra(0);
        int ans1 = INF, ans2 = INF;
        ans1 = min(d[n][0],d[n][1]);
        dijkstra(1);
        ans2 = min(d[n][0],d[n][1]);
        int ans = min(ans1,ans2);
        if(ans == INF){
            cout << -1 << "\n";
        }else{
            cout << ans << "\n";
        }
    }
    

    return 0;
}