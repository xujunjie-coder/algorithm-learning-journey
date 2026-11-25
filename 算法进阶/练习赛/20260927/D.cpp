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
int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, r = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == ')'){
                r++;
            }else{
                l++;
            }
        }
        if(l != r){
            cout << "NO" << "\n";
            continue;
        }else{
            cout << "YES" << "\n";
        }
    }
    

    return 0;
}