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
int const N = 2e5+5;
int T;
int n;
int x[N];
int y[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     v  
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        for(int i = 1; i < n-1; ++i){
            double dx = x[i] - x[i-1];
            double dy = y[i] - y[i-1];
            double k = dy / dx;
            double yy = k * (x[i+1] - x[i]) + y[i];

            double const eps = 1e-8;
            if(y[i+1] > yy + eps){
                cout << "LEFT ";
            }else if(y[i+1] < yy - eps){
                cout << "RIGHT ";
            }else{
                cout << "STRAIGHT ";
            }
        }
        cout << "\n";
    }
    

    return 0;
}