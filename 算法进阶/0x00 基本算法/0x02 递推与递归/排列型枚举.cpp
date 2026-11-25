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
int n;
int const N = 15;
int a[N];
int flag[N];
void dfs(int cur){
    if(cur > n){
        for(int i = 1; i <= n; ++i){
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(flag[i]) continue;
        a[cur] = i;
        flag[i] = 1;
        dfs(cur+1);
        flag[i] = 0;  
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs(1);

    return 0;
}