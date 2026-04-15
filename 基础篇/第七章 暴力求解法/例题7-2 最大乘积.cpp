#include<bits/stdc++.h>
#define L
using namespace std;

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n;
	int kase = 0;
	int flag = 1;
	
	while(scanf("%d",&n) == 1 && n){
		if(!flag) cout << "\n";
		flag = 0;
		int a[20] = {0};
		long long maxx = LLONG_MIN;		// 是「long long 类型整数能表示的最小值」
		for(int i = 0; i < n; ++i){
			scanf("%d",&a[i]);
		}
		for(int i = 0; i < n; ++i){
			long long cur = 1;
			for(int j = i; j < n; ++j){
				cur *= a[j];
				if(maxx < cur) maxx = cur;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n",++kase,maxx);

	}
	
	return 0;
}
