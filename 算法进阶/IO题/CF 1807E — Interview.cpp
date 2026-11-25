#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int const N = 2e5+5;
int T;
int a[N];
ll s[N];
bool ask(int mid,int l){
    cout << "?" ;
    cout << " " << mid - l + 1;
    for(int i = l; i <= mid; ++i){
        cout << " " << i;
    }
    cout << endl;
    int res;
    cin >> res;
    return res == (s[mid] - s[l-1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        //前缀和预处理
        for(int i = 1; i <= n; ++i){
            s[i] = s[i-1] + a[i];
        }
        int l = 1, r = n;
        
        while(l < r){
            int mid = l + (r - l)/2; 
            if(ask(mid,l)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        cout << "! " << l << endl;
    }

    return 0;
}