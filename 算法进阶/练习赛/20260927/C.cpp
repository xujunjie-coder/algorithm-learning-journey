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
int T;
int a[8];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int maxx = -99;
        int index = 0;
        int ans = 0;
        for(int i = 0; i < 7; ++i) {
            cin >> a[i];
            if(a[i] >= maxx){
                maxx = a[i];
                index = i;
            }
            
        }
        for(int i = 0; i < 7; ++i){
            if(i == index){
                ans += a[i];
            }else{
                ans += -a[i];
            }
        }
        cout << ans << "\n";
    }
    

    return 0;
}