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

#define Lo
#define ll long long
#define ull unsigned long long
#define endl '\n'
struct Matrix{
	int a,b;
	Matrix(int a = 0,int b = 0) : a(a),b(b){}
}m[26];
stack<Matrix> s;
int main()
{
#ifdef Lo
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string name;
		cin >> name;
		int k = name[0] - 'A';
		cin >> m[k].a >> m[k].b;
	}
	string ss;
	
	while(cin >> ss){
		int ans = 0;
		int len = ss.length();
		bool error = false;
		for(int i = 0; i < len; ++i){
			if(ss[i] == ')'){
				Matrix m2 = s.top();s.pop();
				Matrix m1 = s.top();s.pop();
				if(m1.b != m2.a){ error = true; break; }
				ans += (m1.a * m1.b * m2.b);
				s.push(Matrix(m1.a,m2.b));	//Matrix(m1.a,m2.b)构造函数
			}else if(isalpha(ss[i])){
				s.push(m[ss[i]-'A']);		//预先存了对应的Matrix对象进m数组中，直接找就可以
			}
		}
		if(error) cout << "error" << endl;
		else cout << ans << endl;
	}
	return 0;
}
