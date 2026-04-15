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

#define Lo
#define ll long long
#define ull unsigned long long
#define endl '\n'
int const N = 1e5+10;
ll a[N];
int T,n;
int main()
{
#ifdef Lo
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	ll maxx = 0;
	ll minn = N;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			maxx = max(maxx,a[i]);
			minn = min(minn,a[i]);
		}
		if(n < 5){
			cout << 'F' << '\n';
			continue;
		}
		if(n % 6)
	}
	return 0;
}
