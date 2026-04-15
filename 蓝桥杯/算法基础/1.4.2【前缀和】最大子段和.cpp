#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int const N = 2e5 + 10;
ll a[N];
ll s[N];
int n;
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	
	ll ret = -1e18;		//记录最终结果
	ll prevmin = 0;		//记录s[i]以前的最小值，因为最开始i=1的时候，前面s[0] = 0;所以初始化为0，没有问题
	for(int i = 1; i <= n;++i){
		ret = max(ret,s[i] - prevmin);	//先算答案与当前位置前缀和-前面最小值时的最大值
		prevmin = min(prevmin,s[i]);	//把当前s[i]加进来以后，更新prevmin；
	}
	cout << ret;
	return 0;
}
