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
vector<int> a;
int n,m;
void dfs(int cur){
    if(a.size() > m || a.size()+(n-cur+1) < m){ return; }
    if(cur > n){
        for(auto x : a){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    //选
    a.push_back(cur);
    dfs(cur+1);
    //复原
    a.pop_back();
    //不选
    dfs(cur+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dfs(1);
    

    return 0;
}