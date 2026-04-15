#include<bits/stdc++.h>
#define LL
using namespace std;
int tot;		//计算递归次数
int n;
int S[90];			//存ASCll码
int L;				
int dfs(int cur){		
	if(tot++ == n){
		int cnt = 1;
		for(int i = 0; i < cur; ++i){ 
			if(i > 0 && i % 4 == 0){
				if(cnt == 16) printf("\n");
				cnt++;
				if(cnt != 17) printf(" ");
				
			} 
			printf("%c",'A'+S[i]);
		}
		
		printf("\n%d\n",cur);
		return 0;		//成功找到解就返回上一层0，从而不用再找了
	}
	for(int i = 0; i < L; ++i){	//尝试将前L个字母
		S[cur] = i;				//试着填入S[cur]
		int ok = 1;				//假设可以放置
		for(int j = 1; 2*j <= cur+1; ++j){	//这里j是用于确定后缀的长度
			int equal = 1;					//这里假设重复是因为要让它重复会需要每个位置都重复才算重复，二不重复可能也有重复的部分位置
			for(int k = 0; k < j; ++k)		//然后k是用来在j长度下的逐个判断每一个的字母是否一样
				if(S[cur - k] != S[cur - k - j]){equal = 0;break;}
			if(equal) {ok = 0; break;}
		}
		//这里本可以直接进入下一个位置，但是加了一个判断条件和返回值的目的
		//当下一层成功找到解会返回0，从而本层也会返回0，不会再执行下面return 1
		//下面的return 1的作用是当本层的都试完了以后还是没有解，就会返回上一层1，继续找下一个解
		if(ok) if(!dfs(cur+1)) return 0;
	}
	return 1;
}

int main(){
#ifdef LL
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	while(scanf("%d %d", &n, &L) == 2 && n){
		tot = 0;
		memset(S,0,sizeof(S));
		dfs(0);
	}
	
	return 0;
}
