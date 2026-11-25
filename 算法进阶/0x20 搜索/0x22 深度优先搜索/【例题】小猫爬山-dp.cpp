#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n,w;
int const N = 20;
int c[N];
int ans;
pair<int,int> dp[1<<N]; //dp[选猫的情况（包括数量和对应只）] = {用车量，最后一辆剩余的w} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for(int i = 0; i < n; ++i) cin >> c[i];

    int tot = 1 << n;
    for(int i = 0; i < tot; ++i){
        dp[i] = {n+1, 0};
    }
    dp[0] = {1,w};
    for(int i = 0; i < tot; ++i){
        for(int j = 0; j < n; ++j){
            if(i & (1 << j)) continue;  //猫在就跳过
            auto nxt = dp[i];   //拷贝一份当作新状态
            if(nxt.second >= c[j]){
                nxt.second -= c[j];
            }else{
                nxt.first++;
                nxt.second = w - c[j];
            }
            int mask = i | (1 << j);
            if(dp[mask].first > nxt.first || (dp[mask].first == nxt.first && dp[mask].second < nxt.second)){
                dp[mask] = nxt;
            }
        }
    }

    cout << dp[tot - 1].first << '\n';
    return 0;
}