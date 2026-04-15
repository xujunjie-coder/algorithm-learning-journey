#include<bits/stdc++.h>
#define L
using namespace std;
typedef long long ll;
int const N = 110;
int ans[N];		//将第i个巨人对应的鬼编号存进去
int n;
struct point{
	int x;
	int y;
	int type;	//0为巨人，1为鬼
	int id;
}points[2*N];

//计算叉积
// 计算叉积：(o->a) × (o->b)
// 结果>0：b在a的逆时针方向（极角更大）
// 结果<0：b在a的顺时针方向（极角更小）
// 结果=0：三点共线（题目保证不会出现）
ll cross(const point& o,const point& a,const point& b){
	return (ll)(a.x-o.x)*(b.y-o.y)-(ll)(a.y-o.y)*(b.x-o.x);
}

//排序规则
bool cmp(const point& a, const point& b, const point& o) {
	return cross(o, a, b) > 0;
}

void solve(int l, int r){
	if(l >= r) return;
	//先找左下角的点
	int o = l;
	for(int i = l+1; i <= r; ++i){
	if(points[i].y < points[o].y || (points[i].y == points[o].y && points[i].x < points[o].x)){
			o = i;
		}
	}
	
	//再把第一个和第o个位置互换，方便后续排序
	swap(points[o],points[l]);
	
	//极角排序
	sort(points + l + 1,points + r + 1,[&](const point &a, const point &b){
		return cmp(a,b,points[l]);
	});
	
	int cnt = 0;
	int mid; 	//标记平分点
	if(points[l].type == 0) cnt = 1;
	else cnt = -1;
	
	for(int i = l+1; i <= r; ++i){
		if(points[i].type == 0) cnt++;
		else cnt --;
		if(cnt == 0){
			mid = i;
			break;
		}
	}
	
	if(points[l].type == 0){
		ans[points[l].id] = points[mid].id;
	}else ans[points[mid].id] = points[l].id;
	solve(l+1,mid-1);
	solve(mid+1,r);
}

int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	while(cin >> n){
		memset(ans,0,sizeof ans);
		for(int i = 1; i <= n; ++i){
			cin >> points[i].x >> points[i].y;
			points[i].id = i;
			points[i].type = 0;
		}
		for(int i = 1; i <= n; ++i) {
			cin >> points[i+n].x >> points[i+n].y;
			points[i+n].id = i;
			points[i+n].type = 1;
		}
		solve(1,2*n);
		for(int i = 1; i <= n; ++i){
			cout << ans[i] << "\n";
		}
	}
	
	return 0;
}
