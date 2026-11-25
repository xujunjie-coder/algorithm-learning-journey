#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int const N = 2e5+10;
int T;
int n;
vector<int> a,b;
vector<tuple<int,int,bool>> t;
int f[N];
void lisan(){
    b = a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
}
int get_id(int x){
    return lower_bound(b.begin(),b.end(),x) - b.begin() + 1;
}
int get_root(int x){
    if(x == f[x]) return x;
    return f[x] = get_root(f[x]);
}
void merge(int x,int y){
    f[get_root(x)] = get_root(y);
}
void init(){
    a.clear();
    b.clear();
    t.clear();
    memset(f,0,sizeof f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        init();
        cin >> n;
        for(int i = 1; i <= n; ++i){
            int x,y; bool e;
            cin >> x >> y >> e;
            t.push_back({x,y,e});
            a.push_back(x);
            a.push_back(y);
        }
        lisan();
        int len = b.size();
        for(int i = 1; i <= len; ++i){
            f[i] = i;
        }
        for (auto [x, y, e] : t) {
            if(e == 1){
                merge(get_id(x),get_id(y));
            }
        }
        int flag = 1;
        for (auto [x, y, e] : t) {
            if(e != 1 && get_root(get_id(x)) == get_root(get_id(y))){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
