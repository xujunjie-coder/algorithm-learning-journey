#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 1e8;
double a[N];
double b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int mx = -1e8;
    cin >> n;
    for(int i = 0; i < n; ++i){ 
        double x;
        cin >> x; 
        int j = floor(x);
        a[j] = x;
        mx = max(mx,j);
    }
    int idx = 0;
    for(int i = 0; i <= mx; ++i){
        if(a[i]){
            b[idx++] = a[i];
        } 
    }
    double ans = 0;
    for(int i = 0; i < n-1; ++i){
        ans = max(ans,abs(b[i] - b[i+1]));
    }
    cout << ans;

    return 0;
}