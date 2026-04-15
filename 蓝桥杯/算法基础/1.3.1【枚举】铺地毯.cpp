#include<bits/stdc++.h>
//#define L
using namespace std;

int const N = 1e4 + 10;
pair<int,int> a[N];
pair<int,int> len[N];
pair<int,int> tar;
int n;
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second >> len[i].first >> len[i].second;
	}
	cin >> tar.first >> tar.second;
	int ans = 0;
	for(int i = n; i >= 1; --i){
		int x = a[i].first;
		int y = a[i].second;
		int xlen = len[i].first;
		int ylen = len[i].second;
		int tarx = tar.first;
		int tary = tar.second;
		if(x <= tarx && x+xlen >= tarx && y <= tary && y+ylen >= tary){
			ans = i;
			break;
		} 
	}
	if(ans) cout << ans;
	else cout << -1;
	return 0;
}
