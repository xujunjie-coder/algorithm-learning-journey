#include <iostream>
using namespace std;
const int N = 100010;
int a[N];

void quick_sort(int l, int r){
    if(l >= r) return;
    int pivot = a[l]; 
    int i = l, j = r;
    while(i < j){
        while(i < j && a[j] >= pivot) j--;
        a[i] = a[j];
        while(i < j && a[i] <= pivot) i++;
        a[j] = a[i];
    }
    a[i] = pivot; 
    quick_sort(l, i-1);
    quick_sort(i+1, r);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    quick_sort(1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
