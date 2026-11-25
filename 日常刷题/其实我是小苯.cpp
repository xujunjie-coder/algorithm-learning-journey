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
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(n == m){
		if(n == 1){
			cout << 0 << " " << 8 << "\n";
		}
		else{
			cout << 0 << " ";
			for(int i = 1; i <= n; ++i){
				if(i == 1)cout << 8;
				else cout << 9;
			}
		}
		return 0;
	}
	if(n < m){
		swap(n, m);
	}
	if(n-m == 1){
		cout << 1 << " ";
		for(int i = 1; i <= n; ++i){
			if(i != n-m+1) cout << 9;
			else cout << 8;
		}
		return 0;
	}
	int dif = n - m - 1;
	for(int i = 0; i < dif; ++i){
		cout << 9;
	}
	for(int i = 1; i <= m; ++i){
		if(i != m) cout << 0;
		else cout << 1 << " ";
	}
	for(int i = 1; i <= n; ++i){
		if(i != n-m+1) cout << 9;
		else cout << 8;
	}
	return 0;
}