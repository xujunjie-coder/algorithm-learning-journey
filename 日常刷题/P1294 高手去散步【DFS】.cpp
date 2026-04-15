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
int const N = 25;
int n,m;
vector<int> road[N];

int main()
{
#ifdef Lo
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int s,e;
		cin >> s >> e;
		road[s].push_back(e);
	}
	return 0;
}
