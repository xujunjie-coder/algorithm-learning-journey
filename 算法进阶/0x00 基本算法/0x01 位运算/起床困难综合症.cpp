#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int n,m;
int ans = 0;
int const N = 1e5+5;
vector<pair<int,int>> a;
int solve(string s){
    if(s == "OR") return 0;
    if(s == "XOR") return 1;
    if(s == "AND") return 2;
    return 3;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        string s;
        int t;
        cin >> s >> t;
        int x = solve(s);
        a.push_back({x,t});
    }
    int x = 0;  //  目前构造的初始攻击力
    for(int i = 29; i >= 0; --i){
        int out0 = 0;
        int out1 = 1;
        for(auto[op,t] : a){
            int tbit = (t >> i) & 1;
            if(op == 0){
                out0 |= tbit;
                out1 |= tbit;
            }else if(op == 1){
                out0 ^= tbit;
                out1 ^= tbit;                
            }else{
                out0 &= tbit;
                out1 &= tbit;
            }
        }
        int bit = 1 << i;
        if(out0 == 1){
            ans |= bit; 
        }else if(out1 == 1 && ((x | bit) <= m)){
            x |= bit;
            ans |= bit;
        }
    }
    cout << ans << "\n";
    return 0;
}