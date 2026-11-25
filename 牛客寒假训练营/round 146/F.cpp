#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // 用于 memset

using namespace std;

long long getCnt(const vector<long long>& cnt, int i) {
    if (i >= 1 && i <= 13) return cnt[i];
    return 0;
}

void solve() {
    int n;
    long long a, b;
    cin >> n >> a >> b;

    vector<long long> cnt(15, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cnt[val]++;
    }

    // 1. 静态构建 DP 数组：极其微小的内存消耗！
    // dp[数字i][上上把顺子x][上一把顺子y]
    long long dp[15][3][3];
    memset(dp, -1, sizeof(dp)); // 全部初始化为 -1

    // 2. 初始化起点
    dp[1][0][0] = 0;

    // 3. 开始状态转移
    for (int i = 1; i <= 13; ++i) {
        
        // x 和 y 的上限永远是 2！这是数学定理给我们的底气。
        for (int x = 0; x <= 2; ++x) {
            for (int y = 0; y <= 2; ++y) {
                // 如果这个历史状态是不存在的，直接跳过
                if (dp[i][x][y] == -1) continue; 

                // 限制 1：只有 1~11 能做顺子的开头
                long long max_z_possible = (i <= 11) ? cnt[i] : 0;
                
                // 限制 2：已经有 x 和 y 消耗了牌 i，必须保证牌够用
                long long remaining_i = cnt[i] - x - y;
                if (remaining_i < 0) continue; // 牌不够，非法状态
                
                // 限制 3：核心降维！z 最大也不超过 2
                long long max_z = min({max_z_possible, remaining_i, 2LL});

                // 尝试所有的 z (0, 1, 2)
                for (int z = 0; z <= max_z; ++z) {
                    
                    long long leftovers = remaining_i - z;
                    long long gain = (z * b) + ((leftovers / 3) * a);

                    dp[i + 1][y][z] = max(dp[i + 1][y][z], dp[i][x][y] + gain);
                }
            }
        }
    }

    // 4. 统计答案
    long long ans = 0;
    // 同样，最后检查的 y 和 z 范围也是 0 到 2
    for (int y = 0; y <= 2; ++y) {
        for (int z = 0; z <= 2; ++z) {
            ans = max(ans, dp[14][y][z]);
        }
    }

    cout << ans << "\n";
}

int main() {
    // 提高 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}