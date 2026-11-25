#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

int n;
ll Hanoi(int n,char from, char fuzhu, char to){
    if(n == 1) return 1;
    ll left = Hanoi(n-1, from , to, fuzhu);
    ll right = Hanoi(n-1, fuzhu, from, to);
    return left + right + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    cin >> n;
    
    cout << Hanoi(n,'A','B','C') << "\n";
    return 0;
}