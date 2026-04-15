#include<bits/stdc++.h>
//#define L
using namespace std;
int A[100];
void print_permutation(int n, int *A, int cur){
	// 递归终止条件：当cur等于n时，说明0~n-1的位置都填满了，输出这个排列
	if(cur == n){
		for(int i = 0; i < n; ++i) printf("%d",A[i]);
		printf("\n");
	}
	// 递归主体：为第cur个位置选择数字
	else{
		// 尝试把1~n的每个数字都放到第cur个位置试试
		for(int i = 1;i <= n;i++){
			int ok = 1;  // 标记当前数字i是否可以放到第cur个位置（默认可以）
			// 检查数字i是否已经出现在前面的位置（0~cur-1）
			for(int j = 0;j < cur; ++j){
				if(A[j] == i) ok = 0;  // 如果i已经用过了，标记为不可用
			}
			// 如果数字i没用过，就把它放到第cur个位置
			if(ok){
				A[cur] = i;
				// 递归：去填充下一个位置（cur+1）
				print_permutation(n,A,cur+1);
			}
		}
	}
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	print_permutation(3,A,0);
	
	return 0;
}
