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
int const N = 105;
int n;
int a[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n > 3) cout << -1 << "\n";
	if(n == 1){
		cout << 1 << "\n";
	}else if(n == 2){
		cout << 1 << " " << 2 << "\n";
		cout << 3 << " " << 4 << "\n";
	}else if(n == 3){
		cout << 1 << " " << 2 << " " << 3 << "\n";
		cout << 5 << " " << 4 << " " << 6 << "\n";
		cout << 7 << " " << 8 << " " << 9 << "\n";
	}	
	return 0;
}