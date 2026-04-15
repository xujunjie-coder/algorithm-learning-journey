#include<bits/stdc++.h>
#define L
using namespace std;
int const N = 1024+10;
int k;
int x,y;
int board[N][N];
int tile;
//特殊格子(x,y),小棋盘左上角坐标(bx,by)，小棋盘边长size；
void chess(int x,int y,int bx,int by,int size){
	if(size == 1) return;
	int len = size / 2;
	int mark = ++tile;
	//特殊块在左上角
	if(x < bx + len && y < by + len){
		chess(x,y,bx,by,len);
	}else{
		board[bx+len-1][by+len-1] = mark;
		chess(bx+len-1,by+len-1,bx,by,len);
	}
	//特殊块在右上角
	if(x >= bx + len && y < by + len){
		chess(x,y,bx + len,by,len);
	}else{
		board[bx+len][by+len-1] = mark;
		chess(bx+len,by+len-1,bx + len,by,len);
	}
	//特殊块在左下角
	if(x < bx + len && y >= by + len){
		chess(x,y,bx,by + len,len);
	}else{
		board[bx+len-1][by+len] = mark;
		chess(bx+len-1,by+len,bx,by+len,len);
	}
	//特殊块在右下角
	if(x >= bx + len && y >= by + len){
		chess(x,y,bx + len,by + len,len);
	}else{
		board[bx+len][by+len] = mark;
		chess(bx+len,by+len,bx + len,by+len,len);
	}
}
int main(){
#ifdef L
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	cin >> k;
	cin >> x >> y;
	int s = (1<<k);
	chess(x,y,1,1,s);
	for(int i = 1; i <= s; ++i){
		for(int j = 1; j <= s; ++j){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
