#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

struct Node {
    int l, w, h;
};

bool cmp(const Node& a, const Node& b) {
    if (a.l != b.l) return a.l > b.l;
    return a.w > b.w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int kase = 0;

    while (cin >> n && n) {
        vector<Node> blocks;
        blocks.reserve(3 * n);  //预分配容器容量能减少运行时开销。

        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            int arr[3] = {a, b, c};
            sort(arr, arr + 3);

            blocks.push_back({arr[1], arr[0], arr[2]});
            blocks.push_back({arr[2], arr[0], arr[1]});
            blocks.push_back({arr[2], arr[1], arr[0]});
        }

        sort(blocks.begin(), blocks.end(), cmp);

        int m = (int)blocks.size(); //记录总的状态量
        vector<int> dp(m, 0); //构造一个长度为m的dp数组，且赋值为0      
        int ans = 0;

        //如何定义 dp、图的方向（谁在前谁在后）、以及用排序建立拓扑顺序决定了下面的循环
        for (int i = 0; i < m; ++i) {
            dp[i] = blocks[i].h;
            for (int j = 0; j < i; ++j) {
                if (blocks[j].l > blocks[i].l && blocks[j].w > blocks[i].w) {
                    dp[i] = max(dp[i], dp[j] + blocks[i].h);
                }
            }
            ans = max(ans, dp[i]);
        }

        cout << "Case " << ++kase << ": maximum height = " << ans << endl;
    }

    return 0;
}
