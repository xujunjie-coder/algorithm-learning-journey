#include<bits/stdc++.h>
#define L
using namespace std;

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
// 1. 定义变量：n是数字个数，p[10]是存储输入数字的数组
	int n, p[10];
	
// 2. 输入n（比如输入3，表示有3个数字）
	scanf("%d",&n);
	
// 3. 输入n个数字到数组p中（比如输入1 1 2，p就变成[1,1,2]）
	for(int i = 0; i < n; ++i) scanf("%d",&p[i]);
	
// 4. 对数组p排序（关键！比如输入2 1 1，排序后变成[1,1,2]）
	sort(p,p+n);
	
// 5. do-while循环：先执行一次循环体，再判断是否继续
	do{
		// 6. 打印当前的排列（比如第一次打印排序后的1 1 2）
		for(int i = 0; i < n; ++i) printf("%d",p[i]);
		printf("\n");
// 7. 核心函数：生成下一个字典序的排列，生成失败则返回false，循环结束
	}while(next_permutation(p,p+n));
	
// 8. 程序结束
	return 0;
}
