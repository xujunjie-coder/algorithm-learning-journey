#include<bits/stdc++.h>
//#define L
using namespace std;
int const N = 1024 + 10;
int m;
int board[N][N];
void solve(int bx, int by, int size){
	if(size == 1){
		board[bx][by] = 1;
		return;
	}
	
	int len = size / 2;

	solve(bx,by,len);
	//左下角
	for(int i = bx; i < bx + len; ++i){
		for(int j = by; j < by + len; ++j){
			board[i][j+len] = board[i][j] + len ;
		}
	}
	//右上角
	for(int i = bx; i < bx + len; ++i){
		for(int j = by; j < by + len; ++j){
			board[i+len][j] = board[i][j+len];
		}
	}
	//右下角
	for(int i = bx; i < bx + len; ++i){
		for(int j = by; j < by + len; ++j){
			board[i+len][j+len] = board[i][j];
		}
	}
//	solve(bx,by+len,len);	//左下角
//	solve(bx+len,by,len);	//右上角
//	solve(bx+len,by+len,len);	//右下角
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> m;
	int length = (1<<m);
	solve(1,1,length);
	for(int i = 1; i <= length; ++i){
		for(int j = 1; j <= length; ++j){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
