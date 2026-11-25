#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long;
#define ll long long;
int const N = 1e4+7;
int a[N];
int ans[N];
int ask(int i,int j){
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}
int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i){
        a[i] = ask(1,i);
    }
    a[1] = ask(2,3);
    ans[1] = (a[2] + a[3] - a[1]) / 2;
    for(int i = 2; i <= n; ++i){
        ans[i] = a[i] - ans[1];
    }
    cout << "!";
    for(int i = 1; i <= n; ++i){
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
