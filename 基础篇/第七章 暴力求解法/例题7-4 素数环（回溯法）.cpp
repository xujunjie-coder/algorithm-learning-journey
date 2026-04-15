#include<bits/stdc++.h>
#define L
using namespace std;
int const MAXN = 40;
int vis[MAXN];	//标记数组(1~n)
int A[MAXN];	//存序列
bool isp[MAXN]; //判断素数数组(2~2n)
bool is_prime(int x){
	if(x <= 1) return false;
	else {
		for(int i = 2; i * i <= x; ++i){
			if(x % i == 0) return false;
		}
		return true;
	}
}
void dfs(int n,int cur){
	if(cur == n && isp[A[n-1] + A[0]]){
		for(int i = 0; i < n; ++i){
			if(i > 0)
				printf(" %d",A[i]);
			else printf("%d",A[i]);
		}
		printf("\n");
	}else for(int i = 2; i <= n; ++i){
		if(!vis[i] && isp[i + A[cur-1]]){
			A[cur] = i; 
			vis[i] = 1;
			dfs(n,cur+1);
			vis[i] = 0;
		}
	}
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n;
	int kase = 1;
	while(scanf("%d",&n) == 1 && n){
		if(kase > 1) printf("\n");
		printf("Case %d:\n",kase++);
		//打表
		for(int i = 2; i < 2*n; ++i) isp[i] = is_prime(i);
		A[0] = 1;
		dfs(n,1);
		
	}
	
	return 0;
}
