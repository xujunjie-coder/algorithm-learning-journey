#include<bits/stdc++.h>
//#define L
using namespace std;
//生成「0~n-1 的不重复递增子集」

//（法一：增量构造法）
// n：集合的大小（元素是0~n-1）
// A：辅助数组，存储当前正在构造的子集
// cur：当前构造到子集的第cur个位置（也表示当前子集的长度）
void print_subset(int n, int *A, int cur){
	for(int i = 0; i < cur; ++i) printf("%d", A[i]);	//采用先输出再递归的方式，输出当前已构造好的子集
	printf("\n");						//cur最开始为0，保证了空集的输出
	//递归生成新的、不重复的子集
	int s = cur ? A[cur-1]+1 : 0;		//首先A[cur-1]是回看上一次递归的最大值，此时cur不在第0层的话就会至少从比上一个值还要大1的值开始
	for(int i = s; i < n; i++){			//这里的循环的作用是保证每一层都能遍历s~n-1个数字
		A[cur] = i;
		print_subset(n, A, cur+1);
	}
}

// (法二：位向量法)
int B[101];	//只含0/1 用于标记是否输出该数字
void print_subset1(int n, int *B, int cur){
	if(cur == n){
		for(int i = 0; i < n; ++i)
			if(B[i]) printf("%d ",i);	// 遍历所有元素，只打印B[i]=1的元素（选中的元素）
		printf("\n");
		return ;						//仅仅结束当前分支
	}
	
	//分支1：选第cur个元素
	B[cur] = 1;
	print_subset1(n, B, cur+1);
	
	//分支2：不选第cur个元素（回溯的关键）
	B[cur] = 0;
	print_subset1(n, B, cur+1);
	/*
	处理cur=0（第一个元素）
	├─ 选（B[0]=1）→ 处理cur=1（第二个元素）
	│  ├─ 选（B[1]=1）→ cur=2 == n=2 → 打印{0,1}
	│  └─ 不选（B[1]=0）→ cur=2 == n=2 → 打印{0}
	└─ 不选（B[0]=0）→ 处理cur=1（第二个元素）
	├─ 选（B[1]=1）→ cur=2 == n=2 → 打印{1}
	└─ 不选（B[1]=0）→ cur=2 == n=2 → 打印空集
	*/
}

// （法三：二进制法）
// n：元素个数（0~n-1），s：表示子集的十进制数（二进制位对应选/不选）
void print_subset2(int n, int s) {
	// 遍历每一位（0~n-1），判断是否选中
	for(int i = 0; i < n; ++i) {
		// 核心位运算：判断s的第i位是否为1
		/*
		其中(1 << i)保证只出现一个1，如001，010，100，
		此时与上s，s为0~n-1的数字分别为000，001，010，011...
		因为加上了判断，所以只有当与后为1才会打印i
		*/
		if(s & (1 << i)) 		
			printf("%d ", i); // 选中则打印该元素
	}
	printf("\n"); // 每个子集打印完换行
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	//法三
	int n = 2;
	for(int i = 0; i < (1 << n); ++i) //(1 << n)这里是2的n次方，即i为所有的n位二进制排列
		print_subset2(n,i);
	
	return 0;
}
