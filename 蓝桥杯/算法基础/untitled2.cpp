#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i=0;i<n;++i) {
		cin >> a[i];
	}
	for (int i=0;i<m;++i) {
		int x,y;
		cin >> x >> y;
		int pos=0,ans=0;
		while (a[x][pos]==a[y][a[y].size()-pos-1]) {
			pos++;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
