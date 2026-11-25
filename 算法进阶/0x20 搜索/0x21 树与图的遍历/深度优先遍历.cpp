#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 1e5;
int const M = 2e5;
int n,m;
int head[N],ver[M],nxt[M],edge[M],tot;
bool v[N];
int a[2*N],timer; //dfs序
int d[N];   //树的深度
int Size[N];    //每个节点的子树大小
void add(int x,int y,int z){
    ver[++tot] = y; edge[tot] = z;
    nxt[tot] = head[x]; head[x] = tot; 
}

void dfs(int x){
    v[x] = 1;
    a[++timer] = x; //进入递归记一次
    for(int i = head[x]; i ; i = nxt[i]){
        int y = ver[i];
        if(v[y]) continue;
        d[y] = d[x] + 1;    //树的深度
        dfs(y);
    }
    a[++timer] = x; //出递归记一次
}   

//树的重心
int ans = N,pos;
void dfs(int x){
    v[x] = 1;
    Size[x] = 1;
    int max_part = 0;  //删除x后分成的子树的大小
    for(int i = head[x]; i ; i = nxt[i]){
        int y = ver[i];
        if(v[y]) continue;
        dfs(y);
        Size[x] += Size[y];
        max_part = max(max_part,Size[y]);   //删掉x以后的最大子树
    }
    max_part = max(max_part,n-Size[x]);     //删掉x以后的最大子树与父亲方向的连通块大小比较
    if(max_part < ans){
        ans = max_part;
        pos = x;
    }
}


//图的连通块-1
void dfs(int x){
    v[x] = 1;
    for(int i = head[x]; i; i = nxt[i]){
        int y = ver[i];
        if(v[y]) continue;
        dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //图的连通块-2
    int cnt = 0; //连通块的个数
    for(int i = 1; i <= n; ++i){
        if(v[i]) continue;
        cnt++;
        dfs(i);
    }


    return 0;
}