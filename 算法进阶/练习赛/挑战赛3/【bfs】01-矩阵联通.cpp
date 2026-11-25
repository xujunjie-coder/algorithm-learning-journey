#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int T;
int n,m;
int const N = 1e5;
char ch;
vector<vector<int>> a,v;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void init(){
    a.assign(n+1,vector<int> (m+1,0));
    v.assign(n+1,vector<int> (m+1,0));
}
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    v[x][y] = 1;
    q.emplace(x, y);

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int xx = cx + dx[i];
            int yy = cy + dy[i];

            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m &&
                a[xx][yy] == 1 && v[xx][yy] == 0) {
                v[xx][yy] = 1;  // 入队时标记，避免重复入队
                q.emplace(xx, yy);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--){
        int sx = 0, sy = 0;
        cin >> n >> m;
        init();
        bool flag = 0;
        for(int i = 1; i <= n;++i){
            for(int j = 1; j <= m; ++j){
                cin >> ch;
                a[i][j] = ch - '0';
                if(a[i][j] == 1){flag = 1;sx = i;sy = j;}
            }
        }
        if(!flag){
            cout << "No" << "\n";
            continue;
        }else{
            bool only = 1;
            bfs(sx,sy);
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= m; ++j){
                    if(v[i][j] == 0 && a[i][j] == 1){
                        only = 0;
                        break;
                    }
                }
            }
            if(only){
                cout << "Yes" << "\n";
            }else{
                cout << "No" << "\n";
            }
        }

    }

    return 0;
}