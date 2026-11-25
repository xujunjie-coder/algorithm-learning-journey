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
int const N = 2e5+10;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int diff = (x - a[k] + n)%n;
    for(int i = 0; i < n; ++i){
        cout << (a[i]+diff+n)%n << " ";
    }

    return 0;
}