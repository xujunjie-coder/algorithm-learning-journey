#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int n;
int const N = 105;
vector<int> a(N);
int ans[N];
int ask(vector<int>& a){
    cout << "?";
    for(auto x : a){
        cout << " " << x;
    }
    cout << endl;
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}
int ask_range(int shift,int l, int r){
    vector<int> a(n,0);
    for(int i = l; i <= r; ++i){
        a[i] = (shift + i)%n+1;
    }
    int res = ask(a);
    return res;
}
void erfen(int shift,int l,int r, int k){
    if(k == 0) return;
    if(l == r) {
        ans[l] = (l+shift)%n+1;
        return;
    }
    int mid = (l+r)/2;
    int res = ask_range(shift,l,mid); //正确的个数
    erfen(shift,l,mid,res);
    erfen(shift,mid+1,r,k-res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> cnt(n);
    for(int i = 0; i < n; ++i){ //偏移量
        vector<int> a(n);
        for(int j = 0; j < n; ++j){
            a[j] = (i + j) % n + 1;
        }
        cnt[i] = ask(a);
        if(cnt[i]){
            erfen(i,0,n-1,cnt[i]);
        }
    }
    cout << "! ";
    for(int i = 0 ; i < n; ++i) cout << " " << ans[i];
    cout << endl;
    return 0;
}           