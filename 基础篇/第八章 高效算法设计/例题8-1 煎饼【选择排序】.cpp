#include<bits/stdc++.h>
using namespace std;
#define L
int a[35], ans[105];
int n, len;

// UVA120 官方定义：翻转 位置k ~ 栈顶
void flip(int k) {
	for (int i = k, j = n; i < j; i++, j--)
		swap(a[i], a[j]);
}

int main() {
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	while (cin >> a[1]) {
		n = 1;
		while(cin.peek() != '\n' && cin >> a[++n]);
		
		// 输出原数组
		for(int i=1;i<=n;i++){
			if(i>1) cout<<" ";
			cout<<a[i];
		}
		cout<<"\n";
		
		len = 0;
		int tar = 1;
		int val = n;
		
		while(tar <= n){
			// 找当前最大值位置
			int pos = 1;
			while(a[pos] != val) pos++;
			
			if(pos == tar){
				tar++;
				val--;
				continue;
			}
			// 第一步翻转：最大值到栈顶
			if(pos != n){
				flip(pos);
				ans[len++] = pos;
			}
			// 第二步翻转：最大值到目标位置
			flip(tar);
			ans[len++] = tar;
			
			tar++;
			val--;
		}
		
		// 核心修复：无多余空格，严格匹配输出
		for(int i=0;i<len;i++){
			if(i>0) cout<<" ";
			cout<<ans[i];
		}
		cout<<" 0\n";
	}
	return 0;
}
