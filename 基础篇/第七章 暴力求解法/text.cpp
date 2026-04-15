#include<bits/stdc++.h>
#define L
using namespace std;

//判断是否是十位数且为0-9
bool is_num(int a, int b){
	if(10000 > b || b > 99999) return false;
	string s1 = to_string(a);
	string s2 = to_string(b);
	string s = s1 + s2;
	
	if(s.length() < 10) s += "0";
	if(s.length() != 10) return false;
	sort(s.begin(),s.end());
	for(int i = 0; i <=9; ++i){
		if(s[i] != '0' + i) return false;
	}
	return true;
}

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int n;
	int flag = 1;
	while(scanf("%d",&n) == 1 && n){
		//执行完一个样例需要空行
		if(!flag) cout << "\n"; 
		flag = 0;
		vector<pair<int,int>> ans;
		for(int i = 1234; i <= 98765; ++i){
			int j = i * n;
			if(is_num(i,j)) ans.push_back({i,j});
		}
		if(ans.empty()) printf("There are no solutions for %d.\n",n);
		else{
			sort(ans.begin(),ans.end());
			for(auto &p : ans){
				printf("%05d / %05d = %d\n",p.first,p.second,n);
			}
		}
	}
	
	
	return 0;
}
