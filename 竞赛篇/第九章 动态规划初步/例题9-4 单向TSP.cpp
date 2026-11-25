#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
int m,n;
int a[11][105];
int d[11][105];
int nxt[11][105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> m >> n){
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }
        int ans = INF;  
        int first = 0;

        for(int j = n-1; j >= 0; --j){
            for(int i = 0; i < m; ++i){
                if(j == n-1) d[i][j] = a[i][j];     //边界
                else{
                    int rows[3] = {i,i-1,i+1};
                    if(i == 0) rows[1] = m-1;
                    if(i == m-1) rows[2] = 0;
                    sort(rows,rows+3);
                    d[i][j] = INF;
                    for(int k = 0; k < 3; ++k){
                        int v = d[rows[k]][j+1] + a[i][j];
                        if(v < d[i][j]){
                            d[i][j] = v;
                            nxt[i][j] = rows[k];
                        }
                    }
                }
                if(j == 0 && d[i][j] < ans){
                    ans = d[i][j];
                    first = i;
                }
            }
        }
        cout << first + 1;
        for(int i = nxt[first][0], j = 1; j < n;i = nxt[i][j], ++j){
            cout << " " << i + 1 ;
        }
        cout << "\n" << ans << "\n";
    }
    return 0;
}