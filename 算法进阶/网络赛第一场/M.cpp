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
#include <unordered_map>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

     int n, m;
    cin >> n >> m;

    unordered_map<string, int> mp;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        mp[s] = 1;
    }

    for(int i = 0; i < m; ++i){
        string s;
        cin >> s;

        int k = mp[s];
        if(k == 0){
            cout << "WRONG\n";
        }else if(k == 1){
            cout << "OK\n";
            mp[s] = 2;
        }else{
            cout << "REPEAT\n";
        }
    }
    return 0;
}