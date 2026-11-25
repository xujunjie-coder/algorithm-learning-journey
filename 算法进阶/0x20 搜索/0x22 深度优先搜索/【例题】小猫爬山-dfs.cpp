#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int n,w;
int const N = 20;
int c[N];
int ans = N + 1;
int sheng[N];
int cnt = 1;
void dfs(int cur,int cnt){
    if(cnt > ans){
        return;
    }
    //边界条件
    if(cur == n + 1){
        ans = min(ans,cnt);
        return;
    }
    for(int i = 1; i <= cnt; ++i){
        if(sheng[i] >= c[cur]){
            sheng[i] -= c[cur];
            dfs(cur+1,cnt);
            sheng[i] += c[cur];
        }
    }
    sheng[cnt+1] -= c[cur];
    dfs(cur+1,cnt+1);
    sheng[cnt+1] += c[cur];
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    // memset(sheng,w,sizeof sheng);
    fill(sheng, sheng + N, w);
    sort(c+1,c+n+1);
    reverse(c+1,c+n+1);
    dfs(1,1);
    cout << ans << "\n";
    return 0;
}