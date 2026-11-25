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
vector<ll> dp(6,0);
ll const MOD = 998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    dp[0] = 1;  //先令边界条件为1，自底而上
    for(int i = 0; i < n; ++i){
        int ch = s[i] - '0';
        auto ndp = dp;
        for(int j = 0; j <= 5; ++j){
            int x = (j*10+ch)%6;
            ndp[x] = (ndp[x]+dp[j])%MOD;  
        }
        dp = ndp;
    }
    cout << (dp[0]-1+MOD)%MOD;

    

    return 0;
}