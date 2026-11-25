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
int T,n,q,k;
int const N = 5e5+5;

int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        set<int> st;
        set<int> st1;
        int ans = 0;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            st.insert(a[i]);
            st1 = st;
        }
        cin >> q;
        while(q--){
            cin >> k;
            for(int i = 0; i < n; ++i) {st1.insert(k-a[i]);} 
            for(int i = 0; ;++i){
                if(!st.count(i)){
                    ans ^= i;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    

    return 0;
}