#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(2*n+2);
    for(int i = 0; i < 2*n+2; ++i) cin >> a[i];
    int xx = 0;
    for(int i = 0; i < 2*n+2; ++i){
        xx ^= a[i];  
    }
    int bit = xx & -xx;
    int x = 0, y = 0;
    for(int i = 0; i < 2*n+2; ++i){
        if(bit & a[i]){
            x ^= a[i];
        }else{
            y ^= a[i];
        }
    }
    if(x > y) swap(x,y);
    cout << x << " " << y;
    return 0;
}