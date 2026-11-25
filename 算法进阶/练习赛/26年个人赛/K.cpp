#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 35;
int n,m,C,B,q;
string s[N];
int a[N][N];
int sta = 0;    //方向状态
int x,y;        //当前位置
int xx,yy;      //仓库位置
int h;          //车上的气球数
int ans;        //送达的气球个数

void zhuan(char c){
    if(c == 'L') sta = (sta+4-1)%4;
    if(c == 'R') sta = (sta + 1) % 4;
}

void jin(char c){
    if(sta == 0){
        if(x - 1 >= 0 && s[x-1][y] != '#'){
            x--;
        }
    }else if(sta == 1){
        if(y+1 < m && s[x][y+1] != '#'){
            y++;
        }
    }else if(sta == 2){
        if(x+1 < n && s[x+1][y] != '#'){
            x++;
        }
    }else{
        if(y-1 >= 0 && s[x][y-1] != '#'){
            y--;
        }
    }
}

char chao(int x){
    if(x == 0) return 'N';
    if(x == 1) return 'E';
    if(x == 2) return 'S';
    if(x == 3) return 'W';
    return 1;
}

void use(char c){
    if(c == 'L' || c == 'R') zhuan(c);
    if(c == 'F'){
        jin(c);
    }
    if(c == 'P'){
        if(x == xx && y == yy){
            int tmp = min(C-h,B);
            B -= tmp;
            h += tmp;
        }
    }
    if(c == 'D'){
        if(a[x][y] != 0 && a[x][y] != -1){
            int tmp = min(h,a[x][y]);
            ans += tmp;
            h -= tmp;
            a[x][y] -= tmp;
        }
    }
}

int main(){
    cin >> n >> m >> C >> B >> q;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    string order;
    cin >> order;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i][j] == 'S'){
                xx = i;
                yy = j;
                a[i][j] = 0;
            }
            else if(s[i][j] == '#'){
                a[i][j] = -1;
            }
            else if(s[i][j] == '.'){
                a[i][j] = 0;
            }else{
                a[i][j] = s[i][j] - '0';
            }
        }
    }
    x = xx;
    y = yy;
    for(int i = 0; i < q; ++i){
        use(order[i]);
    }
    cout << ans << " " << B << " " << h << "\n";
    cout << x+1 << " " << y+1 << " " << chao(sta);
    return 0;
}