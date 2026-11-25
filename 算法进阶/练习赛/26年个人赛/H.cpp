#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 55;
int n,m;
string s[N];
int a[N][N];
bool v[N][N];
int tot = 0;    //连通块编号
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
bool flag = 0;
int cnt;    //记录有灯的区域
int step = 0;
int ans = 0;
void dfs(int x,int y){
    for(int i = 0; i < 4; ++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(a[xx][yy] != 0 && v[xx][yy] == 0 ){

            v[xx][yy] = tot;
            if(a[xx][yy] == 2) flag = 1;
            // cerr << "step: " << step << "\n";
            step++;
            dfs(xx,yy);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {cin >> s[i]; s[i] = "#" + s[i];}

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i][j] == '#') a[i][j] = 0;
            else if(s[i][j] == '.') a[i][j] = 1;
            else if(s[i][j] == 'L') a[i][j] = 2;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(v[i][j] == 0 && a[i][j]){
                v[i][j] = 1;
                tot++;
                flag = 0;
                step = 1;
                if(a[i][j] == 2) flag = 1;
                // cerr << "开始dfs: " << "\n";
                dfs(i,j);
                // cerr << "flag: " << flag << "\n";
                // cerr << "结束dfs: " << "\n";
                if(flag == 1){ 
                    cnt++;
                }else{
                    ans = max(ans,step);
                    // cerr << "ans: "  << ans << "\n";
                }
                
            }
        }
    }
    cout << tot - cnt << " " << ans;
    return 0;
}