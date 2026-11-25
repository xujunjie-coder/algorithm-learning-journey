#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 1e5+5;
int n,m,t;
int ro[N],co[N];
ll f[N];
ll solve(int a[],int n){  //列和列数
    int x = t/n;
    for(int i = 1; i <= n; ++i){
        f[i] = f[i-1] + (a[i] - x);
    }
    sort(f+1,f+n+1);
    int z = f[1+n/2];
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = ans + abs(z-f[i]);
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;
    for(int i = 1; i <= t; ++i){
        int x,y;
        cin >> x >> y;
        ro[x]++;co[y]++;
    }
    
    bool row = (t % n == 0);
    bool col = (t % m == 0);

    ll ans1,ans2;
    if(row){
        ans1 = solve(ro,n);
    }

    if(col){
        ans2 = solve(co,m);
    }

    if(!row && !col){
        cout << "impossible" << "\n";
        return 0;
    }else if( row && !col) {
        cout << "row " << ans1 << "\n";
    }
    else if(!row && col){ 
        cout << "column " << ans2 << "\n";
    }
    else cout << "both " << ans1+ans2 << "\n";

    return 0;
}