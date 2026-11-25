#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
/*
给定长度为 N 的数列 A，多次在线询问，每次给出整数 T，求最大的 k，满足 sum_{i=1}^k :A[i] <= T。
*/
int n,q;
int const N = 1e5+5;
ll s[N];
ll solve(int p, int k,ll t,ll sum){
    while(p){
        if(k + p > n) {
            p /= 2;
            continue;
        }
        ll tsum = sum;
        tsum += s[k+p]-s[k];
        if(tsum <= t){
            sum = tsum;
            k += p;
            p *= 2;
        }else{
            p /= 2;
        }
    }
    return k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        s[i] = s[i-1] + x;
    }
    while(q--){
        ll t;
        cin >> t;
        int p = 1,k = 0;
        ll sum = 0;
        cout << solve(p,k,t,sum) << "\n";
    }
    return 0;
}