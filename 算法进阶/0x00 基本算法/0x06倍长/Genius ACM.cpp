#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 5e5+5;
int T,n,m;
ll k;
int a[N];
ll f[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        for(int i = 0; i < n; ++i)  cin >> a[i];
        sort(a, a+n);
        int mid = n / 2;
        for(int i = 0; i < mid; ++i){
            f[i] = (a[i] - a[n-i]) * (a[i] - a[n-i]);
        }
        if(n & 1) f[++mid] = 0; //为奇数时中间这个为0
        

    }

    return 0;
}