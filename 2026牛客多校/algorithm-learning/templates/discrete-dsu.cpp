// 契约：离线读入全部 int 标签；相等 e=1，不等 e=0；每组独立。
// b 的下标为 [0,m)，并查集编号为 [1,m]；get_id 只接受收集过的值。
// 返回：get_id 为节点编号，get_root 为代表元；输出约束是否相容。
// 用户修改点：输入类型、约束读取方式；超出 int 时同步改标签与查询参数。
// 时间 O(n log n + n alpha(n))，空间 O(n)；按大小合并配合路径压缩。
// 来源：local-discrete-dsu-constraints；助手修正并本地验证，未报告在线 AC。
#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, f, sz;
vector<tuple<int,int,bool>> t;
void lisan(){
    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}
int get_id(int x){
    // [旧错1] +1 只改变返回编号，不改变 vector 的实际下标。
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
int get_root(int x){
    if(x == f[x]) return x;
    // [旧错2] 曾写 get_root(x)：参数不变导致无限递归。
    return f[x] = get_root(f[x]);
}
void merge(int x, int y){
    // [旧错3] 曾直接改 f[x]，必须先找到两边的根。
    x = get_root(x); y = get_root(y);
    if(x == y) return;
    // 工程增强：按大小合并，避免单纯顺序合并产生长链。
    if(sz[x] > sz[y]) swap(x, y);
    f[x] = y;
    sz[y] += sz[x];
}
void init(){
    // [旧错4] 多组输入曾未调用清理，上一组约束会残留。
    a.clear(); b.clear(); t.clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        init();
        int n; cin >> n;
        for(int i = 0; i < n; ++i){
            int x,y; bool e; cin >> x >> y >> e;
            a.push_back(x); a.push_back(y);
            t.push_back({x,y,e});
        }
        lisan();
        int len = (int)b.size();
        // 增强：动态分配 m+1，避免固定数组容纳不了最多 2n 个编号。
        f.resize(len+1); sz.assign(len+1,1);
        // [旧错5] 曾写 f[i]=b[i]：混淆原值和编号，并可能访问 b[len]。
        // [旧错6] 曾初始化 [0,len)，却实际使用 [1,len]，遗漏 f[len]。
        for(int i = 1; i <= len; ++i) f[i] = i;
        for(auto [x,y,e] : t) if(e) merge(get_id(x),get_id(y));
        bool flag = true;
        for(auto [x,y,e] : t){
            if(!e && get_root(get_id(x)) == get_root(get_id(y))){
                flag = false; break;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}
