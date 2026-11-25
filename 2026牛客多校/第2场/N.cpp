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
int T,n,k;
int const N = 2e5+5;
int a[N];
ll pre[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int sum = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a,a+n);
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i-1]+a[i];
        }
        if(k == 1 || k == 2) cout << sum << "\n";
        else{
            if(k % 2 == 0){
                int mid = k / 2;
                int len_r = mid-1;
                ll value_m = 0;
                for(int i = mid; i+1+len_r <= n; ++i){
                    float k_value = (a[i]+a[i+1])/2;
                    int l = mid + 2;
                    int r = i+1+len_r;
                    double value = (pre[r] - pre[l-1])-len_r*k_value;
                    value_m = max(value_m,value);
                }
                
            }else{
                int mid = (k+1) / 2;
                int len_r = mid-1;
                ll value_m = 0;
                for(int i = mid; i+len_r <= n; ++i){
                    int l = i+1;
                    int r = i+len_r;
                    ll value = (pre[r] - pre[l-1])-len_r*a[i];
                    value_m = max(value_m,value);
                }
            }
        }
    }
    

    return 0;
}