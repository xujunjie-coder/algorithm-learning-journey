#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N], tmp[N];


void merge(int l, int mid, int r){
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r){
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    for (int p = l; p <= r; p++) a[p] = tmp[p];
}

void merge_sort(int n){
    for (int len = 1; len < n; len *= 2){
        for (int l = 1; l + len <= n; l += len * 2){
            int mid = l + len - 1;
            int r = min(l + len * 2 - 1, n);
            merge(l, mid, r);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(n);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
