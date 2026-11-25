#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n;
int cnt = 0;
void dfs(int in,int out){
    if(out == n){
        cnt++;
        return;
    }

    if(in < n){
        dfs(in+1,out);
    }
    if(out < in){
        dfs(in,out+1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;
    dfs(0,0);
    cout << cnt;

    return 0;
}