#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 1e5+5;
int T;
int n;
vector<int> p;
int v[N];
void prime(int n){
    for(int i = 2; i <= n; ++i){
        if(v[i]) continue;
        p.push_back(i);
        for(int j = i; j <= n/i; ++j) v[i*j] = 1;
    }
}

int divide(int n){
    int cnt = 0;
    for(auto x : p){
        if(x*x > n) break;
        while(n % x == 0){
            cnt++;
            n /= x;
        }
    }
    if(n > 1) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    prime(10000);
    while(T--){
        cin >> n;
        int cnt = divide(n);
        if(cnt & 1){
            cout << "Alice" << "\n";
        }else{
            cout << "Bob" << "\n";
        }
    }
    

    return 0;
}