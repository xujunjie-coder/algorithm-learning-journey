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
int const N = 2e5 + 10;
int n;
int a, b, c, d;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; ++i){
		if(s[i] == 'A') a++;
		else if(s[i] == 'B') b++;
		else if(s[i] == 'C') c++;
		else if(s[i] == 'D') d++;
	}
	if(a == b && b == c && c == d) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}