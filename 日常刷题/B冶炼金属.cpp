#include<bits/stdc++.h>
#define L
using namespace std;
typedef long long ll;
int const N = 1e4+10;
int n;
ll a[N],b[N],minans;
ll maxans = 1e9;
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
		maxans = min(maxans,a[i]/b[i]);
		minans = max(minans,a[i]/(b[i]+1));
	}
	for(int i = minans; i <= maxans; i++){
		int ok = 1;
		for(int j = 0; j < n; ++j){
			if(a[j] / i != b[j]){
				ok = 0;
				break;
			}
		}
		if(ok){
			minans = i;
			break;
		}
	}
	cout << minans << " " << maxans << "\n";
	return 0;
}
