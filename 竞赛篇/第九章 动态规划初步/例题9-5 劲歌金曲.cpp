#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long
#define endl '\n'
int const N = 55;
int const T = 10005; 

int kase = 0;
vector<ll> vec(N, 0);
ll dp[N][T];    

void init(){
    // 修复 2：把所有状态初始化为 -1，代表“此路不通”
    memset(dp, -1, sizeof dp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    while (K--){
        init();
        ll n, t;
        cin >> n >> t;
        
        // 修复 1：不要 clear 和 push_back，既然大小够，直接按下标 1 到 n 覆盖赋值
        for(int i = 1; i <= n; ++i){
            cin >> vec[i]; 
        }
        
        // 0首歌，消耗0秒，是唯一的合法起点
        dp[0][0] = 0; 
        
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= t - 1; ++j){
                dp[i][j] = dp[i-1][j];
                
                // 如果这首歌能装得下，并且倒退回去的那个状态是合法的（不是 -1），才尝试更新
                if(j - vec[i] >= 0 && dp[i-1][j - vec[i]] != -1){
                    dp[i][j] = max(dp[i][j], dp[i-1][j - vec[i]] + 1);
                } 
            }
        }
        
        // 修复 4：必须在整个 DP 表格填完之后，统一去最后一行寻找“终极答案”
        ll max_songs = -1;
        ll ans_time = 0;
        
        for(int j = 0; j <= t - 1; ++j){
            if(dp[n][j] > max_songs){
                // 如果找到了能唱更多歌的方案，无条件更新
                max_songs = dp[n][j];
                ans_time = j;
            } else if (dp[n][j] == max_songs){
                // 如果唱歌数量一样多，选耗时更长的
                ans_time = max(ans_time, (ll)j);
            }
        }
        
        // 最终输出加上劲歌金曲本身
        cout << "Case " << ++kase << ": " << max_songs + 1 << " " << ans_time + 678 << "\n";
    }

    return 0;
}