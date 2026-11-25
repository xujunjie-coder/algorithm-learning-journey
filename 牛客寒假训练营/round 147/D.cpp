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
int const N = 2e5+5;
int const MVAL = 1e6+5;
int a[N];   //原数组
int dp[MVAL];   //以i为结尾的最长长度
int dp_idx[MVAL];   //记录
int spf[MVAL];  //建表，最小质因数Smallest Prime Factor
int pre[N];
int n;
int max_len;
int end_idx;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp_idx,-1,sizeof dp_idx);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 1; i < MVAL; ++i) spf[i] = i; //先让下表对应的最小质因数为自己
    //埃氏筛批量预处理
    for(int i = 2; i * i < MVAL; ++i){
        if(spf[i] == i){
            for(int j = i*i; j < MVAL; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    //主程序
    for(int i = 0; i < n; ++i){
        vector<int> primes;
        int x = a[i];
        int val = a[i];
        while(x > 1){
            int p = spf[x];
            primes.push_back(p);
            while(x % p == 0){
                x /= p;
            }
        }
        int cur_len = 1;
        int p_idx = -1;
        for(auto p : primes){
            int cad = val / p;
            if(dp[cad] + 1 > cur_len){
                cur_len = dp[cad] + 1;
                p_idx = dp_idx[cad]; // 记录这条最长龙的尾巴下标
            }
        }
        pre[i] = p_idx;
        if(cur_len > dp[val]){
            dp[val] = cur_len;
            dp_idx[val] = i;    //由值到下标的映射
        }
        if (cur_len > max_len) {    //记录全局的
            max_len = cur_len;
            end_idx = i;
        }
    }
    //打印输出
    vector<int> ans;
    while(end_idx != -1){
        ans.push_back(a[end_idx]);
        end_idx = pre[end_idx];
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    return 0;
}