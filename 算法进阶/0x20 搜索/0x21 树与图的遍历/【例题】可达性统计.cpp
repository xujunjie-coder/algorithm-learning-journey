#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n,m;
int const N = 3e4+5;
int const M = 3e4+5;
int head[N],ver[M],nxt[M],tot;
int deg[N]; //入度
int a[N],cnt;   //top序
void add(int x,int y){
    ver[++tot] = y; 
    nxt[tot] = head[x]; head[x] = tot;
    deg[y]++;
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

bitset<N> reach[N];
bool v[N];

void dfs(int x){
    if(v[x]) return;
    v[x] = 1;
    reach[x].set(x);
    for(int i = head[x]; i; i = nxt[i]){
        int y = ver[i];
        
        dfs(y);
        reach[x] |= reach[y];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x,y;
        cin >> x >> y;
        add(x,y);
    }
    topsort();

    for(int i = 1; i <= n; ++i){
        dfs(i);
    }
    for(int i = 1; i <= n; ++i){
        cout << reach[i].count() << "\n";
    }
    return 0;
}