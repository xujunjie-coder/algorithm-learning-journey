#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n,m;
int const N = 1e5,M = 2e5;
int head[N],ver[M],edge[M],nxt[M],tot;
int d[N];   //树的深度或者图的层次
int deg[N]; //预处理节点入度
int a[N], cnt = 0;   //拓扑序

void add(int x,int y){
    ver[++tot] = y;
    nxt[tot] = head[x]; head[x] = tot; 
    deg[y]++;   //预处理每个点的入度
}

void bfs(){
    memset(d,0,sizeof d);
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while(q.size()){
        int x = q.front();
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i];
            if(d[y]) continue;
            d[y] = d[x] + 1;
            q.push(y);
        }
    }
}

void topsort(){
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(deg[i] == 0) q.push(i);
    }
    while(q.size()){
        int x = q.front();
        q.pop();
        a[++cnt] = x;
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i];
            if(--deg[y] == 0){
                q.push(y);
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //拓扑
    cin >> n >> m;  //输入点数，边数
    for(int i = 1; i <= m; ++i){
        int x,y;
        cin >> x >> y;
        add(x,y);
    }
    topsort();
    for(int i = 1; i <= cnt; ++i){
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}