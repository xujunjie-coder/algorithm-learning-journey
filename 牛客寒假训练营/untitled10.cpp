#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int a[MAXN];

int main(){
	int n;
	cin >> n;
	double cp_num = (n-1) * 0.8;
	int sum = 0; 
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i){
		int count = 0; 
		for(int j = 1; j <= n; ++j){
			if(j != i && a[j] <= a[i]) count++;
		}
		if(count >= cp_num) sum += a[i];
	}
	cout << sum << "\n";
	return 0;
}
