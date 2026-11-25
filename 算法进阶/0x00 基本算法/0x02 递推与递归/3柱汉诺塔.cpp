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

/*
举例：4盘
1.把上面3盘借助C移到B   d[n-1]
2.把第4盘从A到C         1
3.把上三盘从B借助A移到C d[n-1]
综上d[n] = 2*d[n-1] + 1;
*/
int n,ans;
ll Hanoi(int n,char from, char fuzhu, char to){
    if(n == 1){
        cout << from << " " << to << "\n";
        return 1;
    }
    ll left = Hanoi(n-1, from , to, fuzhu);
    cout << from  << " " << to << "\n";
    ll right = Hanoi(n-1, fuzhu, from, to);
    return left + right + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    cin >> n;
    ans = Hanoi(n,'A','B','C');
    
    cout << ans << "\n";
    return 0;
}
