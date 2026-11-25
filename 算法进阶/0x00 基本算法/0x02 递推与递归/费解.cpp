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
int const N = 6;
int const INF = 1e6;
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 1,0,0,-1,0 };
int a[N][N];

void press(int b[N][N], int x, int y){
    for(int i = 0; i < 5; ++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && x < 5 && yy >= 0 && yy < 5){
            b[xx][yy] ^= 1;
        }
    }
}

int solve(int mask){
    int b[N][N];
    memcpy(b,a,sizeof a);
    int step = 0;
    //已知第一行排法遍历第一行
    for(int i = 0; i < 5; ++i){
        if((mask >> i) & 1){
            press(b,0,i);
            step++;
        }
    }
    //递推后续
    for(int i = 1; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(!b[i-1][j]){
                press(b,i,j);
                step++;
            }
        }
    }
    //检查最后一排是否合法
    for(int j = 0; j < 5; ++j){
        if(!b[4][j]) return INF;
    }
    return step;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int ans = INF;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        for(int i = 0; i < (1 << 5); ++i){
            ans = min(ans, solve(i));
        }
        if(ans <= 6){
            cout << ans << "\n";
        }else{
            cout << -1 << "\n";
        }
        
    }
    

    return 0;
}