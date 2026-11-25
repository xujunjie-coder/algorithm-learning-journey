#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <string>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 2e5+5;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll sum = 0;
    ll jian = 0;
    for(int i = 0; i < n-1; i++){
        sum += (ll)(n-i-1)*(a[n-1-i]-a[i]);
    }

    cout << sum  << endl;
	return 0;
}