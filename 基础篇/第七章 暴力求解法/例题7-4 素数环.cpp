#include<bits/stdc++.h>
#define L
using namespace std;
int const MAXN = 40;
bool isp[MAXN];


bool is_prime(int x){
	if(x <= 1) return false;
	else{
		for(int i = 2; i * i <= x; ++i){
			if(x % i == 0) return false;
		}
		return true;
	}
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n;
	int kase = 0;
	while(scanf("%d",&n) == 1 && n){
		printf("Case %d:\n", ++kase);	
		//打表
		for(int i = 2; i <= 2*n; ++i){
			isp[i] = is_prime(i);
		}
		int A[MAXN] = {0};
		for(int i = 0 ; i < n; ++i) A[i] = i+1;
		do{
			int  ok = 1;
			for(int i = 0 ; i < n; ++i){
				if(!isp[A[i] + A[(i+1)%n]]){
					ok = 0;
					break;
				}
			}
			if(ok){
				for(int i = 0; i < n; ++i){
					printf("%d ",A[i]);
				}
				printf("\n");
			}
		}while(next_permutation(A+1,A+n));
		
	}
	
	
	return 0;
}
