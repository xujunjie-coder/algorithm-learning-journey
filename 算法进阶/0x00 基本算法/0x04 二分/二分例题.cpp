#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int n,m;
int const N = 1e8+5;
int a[N];
bool check(int size){
    int group = 1, reset = size;
    for(int i = 0; i < n; ++i){
        if(reset > a[i]){
            reset -= a[i];
        }else{
            group++;
            reset -= a[i];
        }
    }
    return group <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 0, r = 1e8+5;
    while(l < r){
        int mid = l + (r-l)/2;
        if(check(mid)){        
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << "\n";

    return 0;
}