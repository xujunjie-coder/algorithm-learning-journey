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
int const N = 105;
int T;
int n;
int a[N][N] = {{0,0,0,0},{0,1,8,6},{0,4,2,9},{0,7,5,3}};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 4; i <= 100; ++i){
        int st = (i-1) * (i-1) + 1;
        a[i][i] = st;
        int x = st;
        x += 2;
        int y = st;
        y += 1;
        for(int j = 1; j <= i - 1; ++j){
            a[i][j] = x;
            x+=2;
            a[j][i] = y;
            y+=2; 
        }
    }
    cin >> T;
    while(T--){
        cin >> n;
        if(n == 2) cout << -1 << "\n";
        else{
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}