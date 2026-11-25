#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int  const N = 1e5+5, M = 1e6+5;
int n,m;
int head[N],ver[M],edge[M],nxt[M],tot;
int v[N],dist[N];
queue<int> q;

void spfa(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; v[1] = 1;
    q.push(1);
    while(q.size()){
        int x = q.front(); q.pop();
        v[x] = 0;   //为啥要加一个这个
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i], z = edge[i];
            if(dist[y] > dist[x] + z){
                dist[y] = dist[x] + z;
                if(!v[y]) {q.push(y); v[y] = 1;}
            } 
        }
    }
}

void add(int x, int y, int z){
    ver[++tot] = y; edge[tot] = z;
    nxt[tot] = head[x]; head[x] = tot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
        //add(y,x,z);如果是无向图就加上这个
    }
    spfa();
    for(int i = 1; i <= n; ++i) cout << dist[i] << "\n";

    return 0;
}