#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define  ll long long 
int const N = 1e4+5;
int const M = 2e4+5;
int const K = 105;
ll const INF = 0x3f3f3f3f3f3f3f3fLL;
int n,m,k;
int head[N],ver[M],edge[M],nxt[M],tot;
bool v[N][K];   
ll d[N][K];  //d[x][r]指的当到x点，且时间余k为r时的最早时间
priority_queue<pair<ll, pair<int,int>>> q;  //{时间{节点，余数}}

void add(int x,int y,int z){
    ver[++tot] = y; edge[tot] = z;//这条边开放的时间
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
            ll t = d[x][r];

            //如果到达时间小于开放时间
            if(t < z){
                ll cnt = (z-t+k-1)/k;   //这里是（z-t)/k上去整写法
                t += cnt*k;
            }
            
            ll nt = t+1;
            int nr = (1+r) % k; //过这一段路以后的新余数
            
            if(d[y][nr] > nt){
                d[y][nr] = nt;
                q.push({-d[y][nr],{y,nr}});
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
