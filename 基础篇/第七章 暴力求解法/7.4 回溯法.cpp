#include<bits/stdc++.h>
//#define L
using namespace std;
// cur：代表放置在第cur行
// C[cur]：表示第cur行的第C[cur]列
// tot：表示解的个数
int tot,n,C[101];
void search(int cur){
	if(cur == n) tot++;
	else for(int i = 0; i < n; ++i){
		int ok = 1;		//判断且默认这一次为合法放置
		C[cur] = i;		//1.先假设可以放置
		for(int j = 0; j < cur; ++j){//2.遍历之前放置的皇后位置
			//2.判断位置是否合理
			if(C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + cur[j]){
				ok = 0;
				break;
			}
		}
		if(ok) search(cur+1);	//若放置合理则进行下一步（这里必须用ok来标记，而不能放在佛尔循环里面的if-else）
	}
}

// cur：代表放置在第cur行
// i：代表列号
// vis[2][]：其中vis[0],vis[1],vis[2]分别为列，副对角线，主对角线
int vis[2][101];
int C1[101];
int tot1;
void search1(int cur){
	if(cur == n) tot1++;
	else for(int i = 0; i < n; ++i){
		if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-1+n]){	//用二维数组直接进行判断
			C[cur] = i;
			vis[0][i] = vis[1][cur+1] = vis[2][cur-i+n] = 1;
			search1(cur+1);
			vis[0][i] = vis[1][cur+1] = vis[2][cur-i+n] = 0;	//这里进行复原因为回溯的时候原来的标记要清0
		}
	}
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	
	
	return 0;
}
