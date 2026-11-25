#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
vector<int> a;
void Perm(vector<int> a,int k, int m){
    if(k == m){
        for(int i = 0; i < m; ++i) cout << a[i];
        cout << "\n";
    }else{
        for(int i = k; i <= m; ++i){
            swap(a[k],a[i]);
            Perm(a, k+1, m);
            swap(a[k], a[i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,m;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
    }
    Perm(a,k,m);

    

    return 0;
}