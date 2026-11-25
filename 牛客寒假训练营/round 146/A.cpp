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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y,z;
    cin >> x >> y >> z;
    int ans = 0;
    ans =z/y*x;
    if(z%y){
        ans+=x;
    }
    cout << ans;


    return 0;
}