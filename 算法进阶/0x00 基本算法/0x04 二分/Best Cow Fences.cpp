#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 1e5+5;
int n,f;
double a[N];
double b[N];
double s[N];

bool check(){
    double ans = -1e10;
    double min_val = 1e10;
    for(int i = f; i <= n; ++i){
        min_val = min(min_val,s[i-f]);
        ans = max(ans,s[i] - min_val);
    }
    if(ans >= 0) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> f;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    } 
    double eps = 1e-5;
    double l = -1e6, r = 1e6;
    while (r - l > eps ){
        double mid = l + (r-l)/2;
        for(int i = 1; i <= n; ++i){ 
            b[i] = a[i] - mid;
            s[i] = s[i-1] + b[i];
        }

        if(check()) l = mid;
        else r = mid;
    }
    cout << (int)(1000*r) << "\n";

    return 0;
}