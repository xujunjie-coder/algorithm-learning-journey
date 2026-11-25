#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 1e4+5;
int n,I,h,r;
int b[N];
int a[N];
set<pair<int,int>> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> I >> h >> r;
    while(r--){
        int l,r;
        cin >> l >> r;
        if(l > r) swap(l,r);
        if(s.count({l,r})) continue;
        else{
            s.insert({l,r});
            b[l+1] -= 1;
            b[r] += 1;
        }

    }
    for(int i = 1; i <= n; ++i){
        a[i] = a[i-1] + b[i];
    }
    int dif = h - a[I];
    for(int i = 1; i <= n; ++i){
        cout << a[i]+dif << "\n";
    }
    return 0;
}