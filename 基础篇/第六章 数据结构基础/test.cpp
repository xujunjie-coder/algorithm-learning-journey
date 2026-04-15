#include<bits/stdc++.h>
#define L
using namespace std;
const int MAXN = 1000+10;


int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n,target[10];
	while(scanf("%d",&n) == 1){
		if(n == 0) {
			cout << "\n";
			scanf("%d",&n);
			if(n == 0) break;
		}
		stack<int> s;
		for(int i = 1; i <= n; i++){
			scanf("%d",&target[i]);
		}
		int o = 1;
		int t = 1;
		bool iss = 1;
		while(t<=n){
			if(o == target[t]) {
				o++;
				t++;
			}else if(o < target[t]){
				s.push(o);
				o++;
			}else{
				if(s.top() != target[t]){
					iss = 0;
					break;
				}else{
					s.pop();
				}
			}
		}
		if(iss) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
	
	return 0;
}
