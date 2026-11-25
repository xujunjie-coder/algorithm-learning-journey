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
int const N = 2.5e5;
int n,m,q;
vector<vector<int>> flag(N,vector<int>(N,-1));
int dx[4]={0,1,-1,0};
int dy[4]={-1,0,0,1};
ll sum[N];
int idx = 1;
int max_v[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x , y , v;
            cin >> x >> y >> v;
            flag[x][y] = 0;
            for(int i = 0; i < 4; ++i){
                int xx = dx[i]+x;
                int yy = dy[i]+y;
                if(flag[x][y] == 0 && flag[xx][yy] != -1){
                    flag[x][y] = flag[xx][yy];
                    sum[flag[xx][yy]]++;
                    max_v[flag[xx][yy]]; 
                }    
                if(flag[x][y] != 0 && flag[xx][yy] != -1){
                    if(flag[x][y] != flag[xx][yy]){
                        int min_i = min(flag[x][y],flag[xx][yy]);
                        sum[min_i]+=sum[flag[xx][yy]];
                        sum[flag[xx][yy]] = 0;
                    }
                }
            }
            if(flag[x][y] = 0){
                flag[x][y] = idx;
                max_v[idx] = v;
                sum[idx] = 1;
                idx++;
            }
            
        }
        if(t == 2){

        }
    }
    

    return 0;
}