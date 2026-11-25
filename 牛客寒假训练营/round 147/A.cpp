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

    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i <= 3; ++i){
        int flag = 1;
        for(int j = 0; j <= 3; ++j){
            if(i != j && s[i] == s[j]){
                flag = 0;
            }
        }
        if(flag) ans++;
    }
    cout << ans;
    return 0;
}