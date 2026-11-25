#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,n;
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;
        if(t%2 == 1) x--;
        else x++;
    }
    cout << x << "\n";

    return 0;
}