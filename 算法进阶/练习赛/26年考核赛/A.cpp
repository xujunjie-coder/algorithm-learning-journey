#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long;
#define ll long long;
int T;
int main(){
     cin >> T;
     while(T--){
        string s;
        cin >> s;
        int len = s.length();
        if(len == 1){
            cout << 0 << "\n";
            continue;
        }
        bool flag = 0;
        int ans = 0;
        for(int i = len - 1; i >= 0;--i){
            if(!flag && s[i] == '0'){
                ans++;
            }else if(!flag && s[i] != '0'){
                flag = 1;
            }else if(flag && s[i] != '0'){
                ans++;
            }
        }
        cout << ans << "\n";
     }
    return 0;
}
