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
    cin.tie(nullptr); 
int T; 
cin >> T; 
while(T--){ 
    int n; 
    cin >> n; 
    vector<char> op(n + 1); 
    vector<int> lastT(n + 1); 
    unordered_map<int, int> lastPush; 
    for(int i = 1; i <= n; ++i){ 
        int x; 
        cin >> op[i] >> x; 
        if(op[i] == '+'){ 
            lastPush[x] = i; 
            lastT[i] = i; 
        }else if(op[i] == 'T'){ 
            lastT[lastPush[x]] = i; 
        } 
    } 

    vector<int> st; 
    string ans; 
    for(int i = 1; i <= n; ++i){ 
        if(op[i] == '+'){ 
            st.push_back(i); 
            ans += '+'; 
        }else{ 
            ans += '?'; 
        } 
        while(!st.empty() && lastT[st.back()] <= i){ 
            st.pop_back(); 
            ans += '-'; 
        } 
    } 
    cout << ans << "\n"; 
} 



return 0; 
} 