#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 2e5+5;
int m,n;
ll a[N];
bool check(ll x){
    ll sum = 0;
    ll cnt = 1; 
    for(int i = 0; i < n; ++i){ 
        if(sum + a[i] <= x){
            sum += a[i];
            // cerr << " a1 " << a[i] << "\n";
            // cerr << " sum1: " << sum << "\n";
            // cerr << " cnt1: " << cnt << "\n";
            
        }else{
            sum = a[i];
            cnt++;
            // cerr << " a2 " << a[i] << "\n";
            // cerr << " sum2: " << sum << "\n";
            // cerr << " cnt2: " << cnt << "\n";
            
        }
    }
    if(cnt > m) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;
    ll maxx = 0;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        maxx = max(maxx,a[i]);
        sum += a[i];
    }
    ll l = maxx, r = sum;
    while(l < r){
        ll mid = l + (r-l)/2;
        // cerr << "l:" << l << "\n";
        // cerr << "mid:" << mid << "\n";
        // cerr << "r:" << r << "\n";
        
        if(check(mid)){
            r = mid;
            
        }else{
            l = mid + 1;
            
        }
    }
    cout << r;
    return 0;
}