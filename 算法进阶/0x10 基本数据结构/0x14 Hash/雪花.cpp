#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int const p = 99991;
int const N = 100010;
int n, tot, snow[N][6], head[N], nxt[N];
//顺时针和逆时针的比较
bool equl(int *a, int *b){
	//1.比较顺时针（i,j分别是a,b数组的两个起始指针）
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			bool eq = 1;
			for(int k = 0; k < 6; ++k){     //依次遍历两个数组的元素
				if(a[(i+k)%6] != b[(j+k)%6]){ eq = 0; }
			}
			if(eq) return 1;
			eq = 1;
			for(int k = 0; k < 6; ++k){
				if(a[(i-k+6)%6] != b[(j+k)%6]){ eq = 0; }
			}
			if(eq) return 1;
		}
	}
	return 0;
}

int H(int *a){
	int sum = 0, mul = 1;
	for(int i = 0; i < 6; ++i){
		sum = (sum + a[i]) % p;
		mul = (long long)mul * a[i] % p;
	}
	return (sum+mul)%p;
}
//链表的插入
bool insert(int *a){
	int hash = H(a);
	for(int i = head[hash]; i ; i = nxt[i]){
		if(equl(a, snow[i])) return 1;
	}
	memcpy(snow[++tot], a, 6 * sizeof(int));
	nxt[tot] = head[hash];  
	head[hash] = tot;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a[10];
		for(int j = 0; j < 6; ++j) cin >> a[j];
		if(insert(a)){ cout << "Twin snowflakes found." << "\n"; return 0; }
	}
	cout << "No two snowflakes are alike." << "\n";
	return 0;
}