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

int mex(int a,int b,int c){
    bool f[4] = {0};
    if(a < 4) f[a] = 1;
    if(b < 4) f[b] = 1;
    if(c < 4) f[c] = 1;
    for(int i = 0; i < 4; ++i){
        if(!f[i]) return i;
    }
    return 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    while(k--){
        int flag = 0;
        for(int i = 0; i < n; ++i){
            b[i] = mex(a[i], a[(i+1) % n], a[(i+n-1)%n]);
            
        }
        if(flag == 0) break; 
        swap(a, b); 
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }

    return 0;
}