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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int x,y;
        cin >> x >> y;
        if(x % 2 != 0 && y % 2 != 0){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n";
        }
    }
    

    return 0;
}