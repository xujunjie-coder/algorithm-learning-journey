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
int const N = 2e5+5;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i){
            if(a[i] % 6 == 0 && a[i]){
                cout << a[i] << " ";
                a[i] = 0;
            }
        }
        for(int i = 0; i < n; ++i){
            if(a[i] && a[i] % 2 == 0){
                cout << a[i] << " ";
                a[i] = 0;
            }
        }
        for(int i = 0; i < n; ++i){
            if(a[i] && a[i] % 2 != 0 && a[i] % 3 != 0){
                cout << a[i] << " ";
                a[i] = 0;
            }
        }
        for(int i = 0; i < n; ++i){
            if(a[i]){
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
    

    return 0;
}