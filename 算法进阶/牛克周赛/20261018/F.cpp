#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 4e3+5;
vector<pair<ll,int>> a,b;   //{价格，下标}
int n;
ll s;


bool check(int k){
    for(int i = 0; i < k; ++i){
        ll val1 = a[i].first;
        int idx1 = a[i].second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> n >> s;
    ll sum;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        a.push_back({x,i});
    }
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        b.push_back({x,i});
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(a[0].first > s || b[0].first > s || a[0].first + b[0].first > s){
        cout << 0 << "\n";
        return 0;
    }

    //二分答案
    int l = 1, r = n;
    while(l < r){
        int mid = l + (r-l)/2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return 0;
}