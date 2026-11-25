#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 5e5+5;
ll a[N];
int n;
ll cnt;
void merge(int l, int mid, int r){
    int b[N];
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(a[i] > a[j]){
            b[k++] = a[j++];
            cnt += mid - i + 1;
        }
        else b[k++] = a[i++];
    }
    while(i <= mid) {
        b[k++] = a[i++];
    }
    while(j <= r) b[k++] = a[j++];
    for(int i = l; i <= r; ++i){
        a[i] = b[i];
    }
}

void solve(int l, int r){
    if(l >= r) return;
    int mid = l + (r-l)/2;
    solve(l,mid);
    solve(mid+1,r);
    merge(l,mid,r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n && n){
        cnt = 0;
        for(int i = 0; i < n; ++i) cin >> a[i];
        solve(0,n-1);
        cout << cnt << "\n";
    }

    return 0;
}