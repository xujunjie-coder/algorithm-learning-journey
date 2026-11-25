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
int const N = 1e6+10;

int T;
int n;
string order;
stack<int> st;
int num;
int a[N];
#define ll long long
#define ull unsigned long long
#define endl '\n'
void pipei(string s, int x){
	if(s == "+") {
		if(a[x]){
			for(; ;)
			{
				int y = st.top();
				cout << "-";
				a[y] = 0;
				st.pop();
				if(y == x){
					break;
				}
				
			}
			cout << "+";
			a[x] = 1;
			st.push(x);
		}else{
			a[x] = 1;
			cout << "+";
			st.push(x);
		}
	}
	if(s == "T" && a[x]) cout << "?";
	if(s == "F" && a[x]){
		for(; ;)
		{
			int y = st.top();
			cout << "-";
			a[y] = 0;
			st.pop();
			if(y == x){
				break;
			}
		}
		cout << "?";
	}
	if(s == "F" && !a[x]){ cout << "?";}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--){
		stack<int>().swap(st);
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> order >> num;
			pipei(order,num);
			
		}
		cout << "\n";
	}
	return 0;
}