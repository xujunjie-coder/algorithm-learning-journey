#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> l;
    vector<int> r;
    vector<pair<int,int>> dot;
    int n,p;
    cin >> n >> p;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
        dot.push_back({x,y});
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    auto d = [&](int x) -> int{
        int st = upper_bound(l.begin(),l.end(),x) - l.begin();  //第一个严格大于x的数
        int ed = lower_bound(r.begin(),r.end(),x) - r.begin();  //第一个大于等于x的数
        return st - ed; //先找到小于等于x的左端点数量，然后减去小于x的右端点的数量。
    };
    for(auto x : dot){
        int l = x.first;
        int r = x.second;
        if(abs(d(l)-d(r)) >= p) ans++;
    }
    cout << ans << '\n';
    return 0;
}