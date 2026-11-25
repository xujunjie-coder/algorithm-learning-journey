#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int q(int n, int m){
    if( (n < 1) || (m < 1) ) return 0;
    if( (n == 1) || (m == 1) ) return 1;
    if(n < m) return(n,n);
    if(n == m) return q(n,m-1)+1;
    return q(n, m-1) + q(n-m, m);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);



    return 0;
}