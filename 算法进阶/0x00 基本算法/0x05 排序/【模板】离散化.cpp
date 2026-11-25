#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
//模板1
int const N = 1e6;
int a[N],b[N];
int n,m;
void discrete_1(){
    sort(a+1,a+n+1);    //下标从1开始
    //去重
    for(int i = 1; i <= n; ++i){
        if(i == 1 || a[i-1] != a[i]){
            b[++m] = a[i];
        }
    }
}
int query(int x){
    return lower_bound(b + 1,b + m + 1, x) - b; //这里取得第一个小于等于x的下标以后减去b的首地址就是真正的下标
}

//模板2
vector<int> c;
vector<int> d;
void discrete_2(){
    sort(c.begin(),c.end());
    d = c;
    d.erase(unique(d.begin(),d.end()),d.end()); //去重
}
int get_id(int x) {
    return lower_bound(d.begin(), d.end(), x) - d.begin() + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}