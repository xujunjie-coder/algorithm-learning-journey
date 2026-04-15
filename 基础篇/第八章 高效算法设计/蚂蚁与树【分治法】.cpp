#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 110;
int ans[N];		
int n;
struct point{
	int x;
	int y;
	int type;	//0蚂蚁，1树
	int id;
}points[2*N];

//叉积（完全正确，不用改）
ll cross(const point& o,const point& a,const point& b){
	return (ll)(a.x-o.x)*(b.y-o.y)-(ll)(a.y-o.y)*(b.x-o.x);
}

// 🔥 【删除了错误的cmp函数！】

void solve(int l, int r){
	if(l >= r) return;
	//找左下角基准点（正确）
	int o = l;
	for(int i = l+1; i <= r; ++i){
		if(points[i].y < points[o].y || (points[i].y == points[o].y && points[i].x < points[o].x)){
			o = i;
		}
	}
	swap(points[o],points[l]);
	
	// ✅ 【唯一修改：正确极角排序！】
	sort(points + l + 1,points + r + 1,[&](const point &a, const point &b){
		return cross(points[l], a, b) > 0;
	});
	
	//找分割点（正确）
	int cnt = (points[l].type == 0) ? 1 : -1;
	int mid; 	
	for(int i = l+1; i <= r; ++i){
		if(points[i].type == 0) cnt++;
		else cnt --;
		if(cnt == 0){
			mid = i;
			break;
		}
	}
	
	//配对（正确）
	if(points[l].type == 0){
		ans[points[l].id] = points[mid].id;
	}else ans[points[mid].id] = points[l].id;
	
	solve(l+1,mid-1);
	solve(mid+1,r);
}

int main(){
	cin >> n;
	//输入蚂蚁
	for(int i = 1; i <= n; ++i){
		cin >> points[i].x >> points[i].y;
		points[i].id = i;
		points[i].type = 0;
	}
	//输入树
	for(int i = 1; i <= n; ++i) {
		cin >> points[i+n].x >> points[i+n].y;
		points[i+n].id = i;
		points[i+n].type = 1;
	}
	solve(1,2*n);
	//输出
	for(int i = 1; i <= n; ++i){
		cout << ans[i] << "\n";
	}
	return 0;
}
