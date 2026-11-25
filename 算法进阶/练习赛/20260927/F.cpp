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
int const N = 3120;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int maxx = -1;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                maxx = max(maxx,a[i] ^ a[j]);
            }
        }
        cout << maxx << "\n";
    }
    

    return 0;
}