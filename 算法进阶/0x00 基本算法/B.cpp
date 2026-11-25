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
int n,q;
ll a[N];
int flag[N];
int cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] > 0){
            cnt++;
            flag[i] = 1;
        } 
    }
    while(q--){
        ll x,v;
        cin >> x >> v;
        for(int i = 1; i <= n; ++i){
            a[i] = max(a[i]-1,0LL);
            if(a[i] == 0 && flag[i]){
                flag[i] = 0;
                cnt--;
           }
        }
        if(x > 0){
            a[x] = max(a[x],v);
            if(a[x] == 0 && flag[x]){
                flag[x] = 0;
                cnt--;
           }
           if(a[x] != 0 && flag[x] == 0){
                cnt ++;
                flag[x] = 1;
           }
        }
        cout << cnt << "\n";
    }
    for(int i = 1; i <= n; ++i){
            if(i != 1) cout << " ";
            cout << a[i] ;
        }
        cout << "\n";

    return 0;
}