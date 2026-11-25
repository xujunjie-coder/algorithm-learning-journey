#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve () {
	int n;cin >> n;
	vector<long long> a(n+1),b(n+1);
	for (int i=1;i<=n;++i) {cin >> b[i];a[i]+=b[i]+a[i-1];}
	long long ans=0;
	for (int i=1;i<=n;++i) {
		for (int j=i;j<=n;++j) {
            if (b[j]>i) {j+=i-1;continue;}
			int cnt=a[j]-a[j-i];
			if (cnt==i) ans++;
		}
	}
	cout << ans << '\n';
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;cin >> T;
	while(T--) solve();
	return 0;
}