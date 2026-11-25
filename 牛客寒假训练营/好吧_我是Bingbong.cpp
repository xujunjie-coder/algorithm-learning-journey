#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

int n;
int h[N];       // 瓶子最大高度
int f[N];       // 父节点
int w[N];       // 管道高度
vector<pair<int, int>> child[N]; // (管道高度w, 子节点编号)
ll ans[N];      // 答案：灌满节点u时的总水量
ll global;      // 全局总用水量（用来记录答案）
ll s[N];
ll dfs_pre(int cur){
    
}
// 核心函数：给u注水，从start_level水位开始
// 返回值：灌满u和子树的用水量
ll dfs(int u) {
    ll cur = 0;     // 当前水位
    ll tot = 0;     // 本次用水量

    // 遍历按w排序后的子节点
    for (auto &p : child[u]) {
        int wv = p.first;
        int v = p.second;

        // 1. 水位涨到管道高度，计算用水量
        tot += wv - cur;
        cur = wv;

        // 2. 灌子节点，把子树用水量加进来
        tot += dfs(v);
    }

    // 3. 灌满自己！
    tot += h[u] - cur;
    // 灌满的瞬间，记录答案
	global += tot;
    ans[u] = global;
    // 返回本次用水量给父节点
    return tot;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 2; i <= n; i++) cin >> f[i];
    for (int i = 2; i <= n; i++) cin >> w[i];

    // 建邻接表 + 排序
    for (int i = 2; i <= n; i++) {
        child[f[i]].emplace_back(w[i], i);
    }
    for (int i = 1; i <= n; i++) {
        sort(child[i].begin(), child[i].end());
    }

    global = 0;
    dfs(1); // 根节点从0水位开始灌

    // 输出答案
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}