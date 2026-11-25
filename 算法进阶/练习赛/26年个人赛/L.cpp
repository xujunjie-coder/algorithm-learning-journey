#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n,k,d;
int const N = 2e5+5;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> d;
    for(int i = 0; i < n; ++i) cin >> a[i];
    map<int,int> cnt;   //{数字，次数},cnt.size是种类，cnt.begin是最小值，rbegin是最大值
    int l = 0, ans = 0;
    for(int r = 0; r < n; ++r){
        cnt[a[r]]++;

        while(cnt.size() > k || cnt.rbegin() -> first - cnt.begin() -> first > d){
            if(--cnt[a[l]] == 0) cnt.erase(a[l]);
            l++;
        }
        ans = max(ans,r - l + 1);
    }
    cout << ans << "\n";

    return 0;
}