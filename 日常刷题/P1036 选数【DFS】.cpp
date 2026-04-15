#include <bits/stdc++.h>

inline bool isprime(int x) { // 判断一个数是否是素数
	if (x == 1) return false; // 注意这步特判是必需的
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

const int N = 25;
int a[N], ans, n, k;

void dfs(int cnt, int sum, int cur) {
	// 现在已经选了 cnt 个数，当前总和为 sum
	// cur 是这次选数的起始下标，即我们从 a[cur] 开始选数枚举
	if (cnt == k) {
		if (isprime(sum))
			++ans;
		return ;
	}
	
	// 已经选了 cnt 个数，这次选完后，还有 k - cnt - 1 个数要选择
	// 因此 a[n - (k - cnt - 1)] 即 a[n - k + cnt + 1] 是枚举的终点
	for (int i = cur; i <= n - k + cnt + 1; ++i)
		dfs(cnt + 1, sum + a[i], i + 1);
	return ;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}
