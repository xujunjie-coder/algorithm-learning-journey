#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N], tmp[N];

void merge(int l, int mid, int r){
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int p = l; p <= r; p++) a[p] = tmp[p];
}

void merge_sort(int l, int r){
    if(l >= r) return;
    int mid = l + (r-l) / 2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    merge(l, mid, r);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(1, n); 
    
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
