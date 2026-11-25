// 助手提供的参考实现，非用户补交代码；验证结果见 young-tableaux-methods-verification.json。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 35;
int k, sum;
ll n[5], a[N];

void init(){
    sum = 0;
    for(int i = 0; i < k; ++i) sum += n[i];
    for(int i = 1; i <= sum; ++i) a[i] = i;
}

ll solve(){
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n[i]; ++j){
            ll h = n[i] - j;
            for(int r = i+1; r < k; ++r)
                if(n[r] > j) ++h;
            for(int t = 1; t <= sum && h > 1; ++t){
                ll g = gcd(a[t], h);
                a[t] /= g;
                h /= g;
            }
        }
    }
    ll ans = 1;
    for(int i = 1; i <= sum; ++i) ans *= a[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> k && k){
        fill(n, n+5, 0LL);
        for(int i = 0; i < k; ++i) cin >> n[i];
        init();
        cout << solve() << '\n';
    }
}
