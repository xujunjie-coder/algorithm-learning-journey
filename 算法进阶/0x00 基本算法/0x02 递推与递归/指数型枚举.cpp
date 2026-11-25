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
int n;
void calc(int cur){
    if(cur == n+1){   //因为加入n是在判断条件以后的，所以这里应该是判断cur == n+1
        for(int i = 0; i < a.size(); ++i){
            if(i != 0) cout << " ";
            cout << a[i];
        }
        cout << "\n";
        return; //终止当前递归路径
    }
    //选
    a.push_back(cur);
    calc(cur+1);
    //保留现场
    a.pop_back();
    //不选
    calc(cur+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    calc(1);
    

    return 0;
}