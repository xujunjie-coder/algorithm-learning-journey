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
int const mod = 9901;
ll A,B;
//快速幂（模板）
ll qpow(ll a, ll b){
    ll res = 1;
    a %= mod;
    while( b > 0){
        if(b & 1){
            res = a * res % mod;
        }
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}
//分治求等比数列和
ll sum(ll p, ll c){
    p %= mod;    // 这里忘记取模了；
    if(c == 0){
        return 1;
    }
    if(c % 2 == 0){
        return ((qpow(p,c / 2)+1) % mod * sum(p,c/2 - 1) % mod + qpow(p,c)) % mod;
    }else{
        return (qpow(p,(c+1) / 2) + 1) % mod * sum(p,(c - 1)/2) % mod;
    }
}

//分解质因数
int solve(ll a, ll b){
    ll ans = 1;
    if(a == 0){ return 0; }
    if(a == 1){ return 1; }
    ll x = a;  //防止修改a的值影响后续遍历
    for(int i = 2; i * i <= a; ++i){
        //这一层if-else是在找a的因子
        if( a % i != 0){ continue; }
        else{
            ll cnt = 0;
            //算当前这个因数的次数cnt
            while( x % i == 0){
                x /= i;
                cnt++;
            }
            ans = ans * sum(i,cnt*b) % mod;//然后用等比求和
        }
    }
    if(x > 1){  //这里是当还有剩余质数时也要加进来别忘了乘B
        ans = ans * sum(x,b) % mod;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B;
    cout << solve(A,B);
    

    return 0;
}