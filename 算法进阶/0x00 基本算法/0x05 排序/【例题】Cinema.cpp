#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int const N = 2e5+5;
int const M = 2e5+5;
int n;
int m;
int b[M];
int c[M];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,int> cnt;
    cin >> n;
    for(int i = 1; i <= n; ++i){ 
        int x;
        cin >> x;
        cnt[x]++;
    }    //科学家
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> b[i];    //语音
    for(int i = 1; i <= m; ++i) cin >> c[i];    //字幕

    int ans = 0;
    int yin = -1, zi = -1;
    for(int i = 1; i <= m; ++i){
        if(cnt[b[i]] > yin || (cnt[b[i]] == yin && cnt[c[i]] > zi)){
            yin = cnt[b[i]];
            zi = cnt[c[i]];
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}