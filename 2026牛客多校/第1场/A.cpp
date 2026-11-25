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
bool is_yuan(char ch){
    char yuan[5] = {'a','e','i','o','u'};
    for(int i = 0; i < 5; ++i){
        if(ch == yuan[i]){
            return 1;
        }
    }
    return 0;
}
bool is_geng(string s){
    int len = s.size();
    if(len != 8) return 0;
    s = " " + s;
    for(int i = 1; i <= len; ++i){
        if(i % 2 == 0 && !is_yuan(s[i])){
            return 0;
        }
        if(i % 2 == 1 && is_yuan(s[i])){
            return 0;
        }
    }
    return 1;    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(is_geng(s)){
            cout << "Suspected Virus" << "\n";
        }else{
            cout << "Well-Being" << "\n";
        }
    }

    return 0;
}