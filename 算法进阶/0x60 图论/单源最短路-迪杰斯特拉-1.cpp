#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int const N = 3010;
int n,m;
int d[N], a[N][N];
bool v[N];

void dijkstra(){
    memset(d, 0x3f, sizeof d);
    memset(v, 0, sizeof v);
    d[1] = 0;
    for(int i = 1; i < n; ++i){
        int x = 0;
        for(int j = 1; j <= n; ++j){
            if(!v[j] && (x == 0 || d[j] < d[x])) x = j;
        }
        v[x] = 1;
        for(int y = 1; y <= n; ++y){
            d[y] = min(d[y],d[x] + a[x][y]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(a,0x3f,sizeof a);
    for(int i = 1; i <= n; ++i) a[i][i] = 0;    //自己到自己为0
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;     //x -> y 权值z
        a[x][y] = min(a[x][y],z);
    }

    dijkstra();
    for(int i = 1; i <= n; ++i) cout << d[i] << "\n";
    return 0;
}