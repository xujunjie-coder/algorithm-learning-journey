#include<bits/stdc++.h>
//#define L
using namespace std;
int A[100];
int P[3] = {1,1,1};

//使用前提是输入的P数组是已经排好序的
void print_permutation(int n,int *P, int *A, int cur){
	if(cur == n){
		for(int i = 0; i < n; ++i) printf("%d",A[i]);
		printf("\n");
	}
	// 递归主体：为第cur个位置选择数字
	else{
	// 外层循环：遍历原数组P的每一个元素，尝试把它放到A的第cur个位置
		for(int i = 0;i < n;i++){
			//若当前元素与前一个元素相同，则不进入循环
			if(i && P[i] == P[i-1]) continue;
			
			// 初始化两个计数器：c1记录“已用次数”，c2记录“总可用次数”
			int c1 = 0, c2 = 0;
			
			// 1. 计算c1：A数组中[0~cur-1]位置里，已经用了多少个P[i]
			// 比如P[i]是1，cur=2（说明A[0]、A[1]已经填了），如果A[0]=1、A[1]=2，那c1=1
			for(int j = 0; j < cur; ++j) if(A[j] == P[i]) c1++;		
			
			// 2. 计算c2：原数组P中，P[i]这个数总共有多少个（总可用次数）
			// 比如P是[1,1,2]，P[i]=1时，遍历整个P会发现有2个1，所以c2=2
			for(int j = 0; j < n; ++j) if(P[i] == P[j]) c2++;		
			
			// 3. 核心判断：只要“已用次数” < “总可用次数”，就可以再用一次P[i]
			// 比如P[i]=1，c1=1、c2=2 → 1<2，说明还能再用一次1，就把它放到A[cur]位置
			if(c1 < c2){										
				A[cur] = P[i];
				// 递归：填下一个位置（cur+1）
				print_permutation(n,P,A,cur+1);
			}
		}
	}
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	print_permutation(3,P,A,0);
	return 0;
}
