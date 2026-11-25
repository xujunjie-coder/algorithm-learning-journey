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
int const N = 55;
int const T = 205;
int const INF = 0x3f3f3f3f;
int n,maxT;
int kase = 0;
int t[N];   //从i到i+1站花费的时间
int t1[N],t2[N];
int m1,m2;  //从起点和从终点出发的火车数量
int d[N],e[N];  //出发时间
int dp[T][N];   //dp[T][n]从i时刻在车站j最少需要等待的时间
int has_train[T][N][2];     //预处理

//初始化
void init(){
    memset(has_train,0,sizeof has_train);
}
//预处理时间前缀和与后缀和
void pre(){
    t1[0] = 0;
	for(int i = 1; i <= n-1; ++i){
        t1[i] = t[i] + t1[i-1];
    }

    t2[n] = 0;
    for(int i = n-1; i >= 1; --i){
        t2[i] = t[i] + t2[i+1];
    }
}

//预处理每个站点对应时间是否有车
void prev(){
    for(int i = 1; i <= m1; ++i){
        has_train[d[i]][1][0] = 1;
        for(int j = 1; j <= n-1; ++j){
            has_train[d[i] + t1[j]][j+1][0] = 1;
        }   
    }
    for(int i = 1; i <= m2; ++i){
        has_train[e[i]][n][1] = 1;
        for(int j = n-1 ; j >= 1; --j){
            has_train[e[i] + t2[j]][j][1] = 1; //这里的车站就是j而不用再-1;
        }   
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n && n)
    {
        cin >> maxT;
        for(int i = 1; i <= n-1; ++i) cin >> t[i];
        cin >> m1;
        for(int i = 1; i <= m1; ++i) cin >> d[i];
        cin >> m2;
        for(int i = 1; i <= m2; ++i) cin >> e[i];
        init();
        pre();
        prev();
        //刷表法
        //1.初始化各个值(因为是从后往前推，边界就是最后dp[maxT][i]这一行)
        for(int i = 1; i <= n-1; ++i) dp[maxT][i] = INF;    //设置边界条件，同时INF为死路的判定
        dp[maxT][n] = 0;
        //2.dp
        for(int i = maxT-1; i >= 0; --i){
            for(int j = 1; j <= n; ++j){
                //决策1；等待1分钟
                dp[i][j] = dp[i+1][j] + 1;
                //决策2：如果存在往右开的车就乘坐
                if(has_train[i][j][0] && i+t[j] <= maxT && j < n){
                    dp[i][j] = min(dp[i][j],dp[i+t[j]][j+1]);
                }
                //决策3：如果存在往左开的车就乘坐
                if(has_train[i][j][1] && i+t[j-1] <= maxT && j > 1){
                    dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);
                }
            }
        }

        cout << "Case Number " << ++kase << ": ";
        if(dp[0][1] >= INF) cout << "impossible\n";
        else cout << dp[0][1] << "\n";
    }
    

    return 0;
}
