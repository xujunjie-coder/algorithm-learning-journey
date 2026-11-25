#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

//1.定义f[SIZE]，存储父节点，根节点的父节点为自己
int const SIZE = 1e6;
int f[SIZE];

//3.GET操作
int get(int x){
    if(x == f[x]) return x;
    return f[x] = get(f[x]);    //路径压缩，f的值直接赋值给根
}

//4.merge操作
void merge(int x, int y){
    f[get(x)] = get(y);     //把x所在的树合并到y所在的树上
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    //2.初始化并查集
    for(int i = 1; i <= n; ++i) f[i] = i;


    return 0;
}