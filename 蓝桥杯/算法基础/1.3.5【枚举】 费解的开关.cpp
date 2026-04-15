#include<bits/stdc++.h>

using namespace std;
int const N = 10;
int n = 5;
int a[N];	//将每一行用二进制数来表示
int t[N];	//备份a数组
int cal(int x){
	int cnt = 0;
	while(x){
		cnt++;
		x -= x & -x;
	}
	return cnt;
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int T; cin >> T;
	while(T--){
		//输入状态
		memset(a,0,sizeof a);	//清空上一个样例的数组
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				char ch; cin >> ch;
				//将0，1置换
				if(ch == '0') a[i] |= 1 << j;
			}		
		}
		int ret = 0x3f3f3f3f;	//记录最终答案
		for(int st = 0; st < (1 << n); st++){	//遍历第一行所有的按法
			int push = st;
			int cnt = 0;	//统计每一种按法下按的次数
			memcpy(t,a,sizeof a);
			for(int i = 0; i < n; ++i){	//遍历每一行
				cnt += cal(push);	//将每一次的push次数统计出来
				//修改当前行的状态
				t[i] = t[i] ^ push ^ (push << 1) ^ (push >> 1);
				t[i] &= (1 << n) - 1;	//把超出位置0
				//修改下一行的状态
				t[i+1] = t[i+1] ^ push;
				//推导下一行的按法
				push = t[i];
			}
			if(t[n - 1] == 0) ret = min(ret,cnt);	//如果成功关闭则统计最小值
		}
		if(ret > 6) cout << -1 << "\n";
		else cout << ret << "\n";
	}
	
	return 0;
}
