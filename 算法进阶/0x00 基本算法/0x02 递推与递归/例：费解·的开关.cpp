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
int const N = 10;
int const INF = 0x3f3f3f;

int a[N][N];
int n;
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 1,0,0,-1,0 };
void press(int b[N][N],int x,int y){
    for(int i = 0; i < 5; ++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 5 && xx >=0 && yy < 5 && yy >=0){
            b[xx][yy] ^= 1; 
        }     
    }
}
int solve(int mask){    //这里就是传入的所有可能的情况
    int b[N][N];
    memcpy(b,a,sizeof a);
    int step = 0;
    //第一行的全部可能
    for(int j = 0; j < 5; ++j){ 
        if(mask >> j & 1){  
            press(b,0,j);
            ++step;
        }
    }
    //后面逐行递推
    for(int i = 1; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(!b[i-1][j]){
                press(b,i,j);
                step++;
            }
        }
    }
    //弄完以后找到最后一行判断合法步数，找最少的
    for(int j = 0; j < 5; ++j){
        if(!b[4][j]) return INF;
    }
    return step;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
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
        for(int i = 0; i < (1<<5); ++i){
            ans = min(ans,solve(i));
        }
        if(ans <= 6){
            cout << ans << "\n";
        }else{
            cout << -1 << "\n";
        }
        
    }
    return 0;
}