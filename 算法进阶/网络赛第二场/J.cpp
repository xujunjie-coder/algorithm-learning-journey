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

    unordered_map<string, int> mp;
    string a[] = {
        "WrongProblem",
        "SameProblem",
        "UnreasonableLimitForProblem",
        "WeakTestsForProblem",
        "BadProblem"
    };
    int w[] = {100, 30, 5, 3, 1};
    for(int i = 0; i < 5; ++i){
        for(char c = 'A'; c <= 'L'; ++c){
            mp[a[i] + c] = w[i];
        }
    }
    mp["UnreasonableProblemArrangement"] = 10;
    int T;
    cin >> T;
    while(T--){
        int n, p;
        cin >> n >> p;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            sum += mp[s];
        }
        if(sum > p){
            cout << "Joker\n";
        }else{
            cout << "Judger\n";
        }
    }


    return 0;
}