#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.length();
        bool flag = 0;
        int a = 0,b = 0;
        int jinzhi = 1;
        for(int i = n-1; i >= 0; --i){
            if(s[i] == '+') {flag = 1;jinzhi = 1 ;continue;}
            if(!flag) a = a + jinzhi * (s[i]-'0');
            if(flag) b= b + jinzhi * (s[i]-'0');
            jinzhi *= 10;
        }
        cout << a+b << "\n";
    }

    return 0;
}