#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 2e5+5;
int T,n;

bool cmp (int a, int b){
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        vector<int> a;
        cin >> n;
        for(int i = 0; i < n; ++i){ 
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int flag = 0;
        int sum = 1;
        int len = a.size();
        for(int i = 1; i < len; ++i){
            if(a[i] == a[i-1]) sum++;
            if(a[i] != a[i-1]) {
                if(sum % 2 == 1) {
                    flag = 1;
                    break;
                }
                sum = 1;
            }
        }
        if(flag) cout << "red" << "\n";
        else cout << "fang" << "\n";
    }
    

    return 0;
}