#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int x = a[n/2];
    
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        sum = sum + abs(a[i]-x);
    }
    cout << sum << "\n";
    return 0;
}