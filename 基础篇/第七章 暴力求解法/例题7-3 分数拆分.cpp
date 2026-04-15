#include<bits/stdc++.h>
#define L
using namespace std;

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int k;
	while(scanf("%d",&k) == 1 && k){
		vector<pair<int,int>> vec;
		int sum = 0;
		for(int b = 1;b <= k;++b){
			int a = k*k % b;
			int c = k*k / b;
			if (a == 0 && c >= b ){
				sum ++;
				vec.push_back({c+k,b+k});
			}
		}
		printf("%d\n",sum);
		for(auto &p : vec){
			printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
		}
	}
	
	return 0;
}
