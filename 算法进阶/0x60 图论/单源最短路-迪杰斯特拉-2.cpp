#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int const N = 1e5+5, M = 1e6+5;
int head[N], ver[M], edge[M], nxt[M], tot; //邻接表
int d[N];
bool v[N];
int n,m;
//priority_queue 的三个参数依次是：元素类型、底层容器、比较规则
priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;   //这里piar<距离，点号>，优先队列默认大根堆
               
void add(int x, int y, int z){
    ver[++tot] = y; edge[tot] = z;
    nxt[tot] = head[x]; head[x] = tot;
}

void dijkstra(){
    memset(d, 0x3f, sizeof d);
    memset(v, 0, sizeof v);
    d[1] = 0;
    pq.push(make_pair(0, 1));
    while(pq.size()){
        int x = pq.top().second; pq.pop();  // 取出最小的元素
        if(v[x]) continue;                  //如果已经选中就下一次循环
        v[x] = 1;                           //标记选这个
        for(int i = head[x]; i ; i = nxt[i]){   //遍历该点所有边
            int y = ver[i], z = edge[i];    
            if(d[y] > d[x] + z){            //判断目前存的到y的距离d[y]和到x的距离d[x]+从x到y的距离z谁更小就更新
                d[y] = d[x] + z;
                pq.push(make_pair(d[y],y)); //存入小根堆中
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
    }
    dijkstra();
    for(int i = 1; i <= n; ++i) cout << d[i] << "\n";

    return 0;
}