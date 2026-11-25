#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 1e5+5;
int tot = 0;    //存边的编号
int val[N];     //存边的权值
int head[N];    //head[点号] = 边号，起点->边
int ver[N];     //ver[边号] = 点号，边->终点
int nxt[N];     //nxt[边号] = 边号，边->下一条边
//头插法
void add_diradj(int x,int y,int v){
    ver[++tot] = y; //先把新加进来的点赋予边号
    val[tot] = v;   //如果有权值就赋值
    nxt[tot] = head[x];    //先接上后面的边
    head[x] = tot;         //边号
}

//找以x的周围的边
void find(int x){
    for(int i = head[x]; i; i = nxt[i]){
        int y = ver[i];
        int v = val[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    

    return 0;
}