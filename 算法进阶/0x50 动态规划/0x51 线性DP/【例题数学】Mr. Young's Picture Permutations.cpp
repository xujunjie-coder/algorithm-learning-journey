#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int

int const N = 35;
int k, sum;
ll n[5];
ll a[N];

void init(){
    sum = 0;
    for(int i = 0; i < k; ++i)
        sum += n[i];

    // 暂时不相乘，分别保存阶乘中的每个因子
    for(int i = 1; i <= sum; ++i)
        a[i] = i;
}

ll solve(){
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n[i]; ++j){
            // 右边的格子数 + 自己
            ll h = n[i] - j;

            // 同一列下方的格子数
            for(int r = i + 1; r < k; ++r){
                if(n[r] > j) ++h;
            }

            // 将当前勾长与阶乘因子逐步约分
            for(int t = 1; t <= sum && h > 1; ++t){
                ll g = gcd(a[t], h);
                a[t] /= g;
                h /= g;
            }
        }
    }

    // 所有分母都约掉后，再计算剩余因子的乘积
    ll ans = 1;
    for(int i = 1; i <= sum; ++i)
        ans *= a[i];

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> k && k){
        fill(n, n + 5, 0LL);
        for(int i = 0; i < k; ++i)
            cin >> n[i];

        init();
        cout << solve() << "\n";
    }

    return 0;
}