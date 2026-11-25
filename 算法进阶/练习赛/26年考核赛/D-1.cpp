#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

int const N = 1e4+5;
int const M = 2e4+5;
int const K = 105;
int const INF = 0x3f3f3f3f;

int n,m,k;
int head[N],ver[M],edge[M],nxt[M],tot;
bool v[N][K];
int d[N][K];
priority_queue<pair<int,pair<int,int>>> q;

void add(int x,int y,int z){
    ver[++tot] = y; edge[tot] = z;
    nxt[tot] = head[x]; head[x] = tot;
}

void solve1(){
    memset(d,0x3f,sizeof d);
    memset(v,0,sizeof v);
    d[1][0] = 0;
    q.push({0,{1,0}});
    while(q.size()){
        int x = q.top().second.first;
        int r = q.top().second.second;
        q.pop();
        if(v[x][r]) continue;
        v[x][r] = 1;
        for(int i = head[x]; i; i = nxt[i]){
            int y = ver[i], z = edge[i];
            int t = d[x][r];
            if(t < z){
                int cnt = (z - t + k-1) / k;
                t += cnt*k;
            }

            int nt = t + 1;   //到y的新时间
            int nr = nt % k;
            if(d[y][nr] > nt){
                d[y][nr] = nt;
                q.push({-d[y][nr], {y,nr}});
            }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    solve1();
    
    if(d[n][0] == INF){
        cout << -1 << "\n";
    }else{
        cout << d[n][0] << "\n";
    }
    return 0;
}
