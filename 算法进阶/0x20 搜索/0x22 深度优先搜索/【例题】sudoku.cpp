#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
char a[9][9];
int row[9],liner[9];
int gong[9][9];
int hefa[9][9];
bool flag;
void init(){
    memset(row,0,sizeof row);
    memset(liner,0,sizeof liner);
    memset(gong,0,sizeof gong);
    memset(hefa,0,sizeof hefa);
    flag = 0;
}
//传入一个.
void dfs(){
    if(flag) return;
    //初始化记录最小合法位置及其个数
    int x = -1, y = -1;
    int minn = 10;
    //找最小合法
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(a[i][j] != '.')continue;
            int mask = ((1 << 9) - 1) ^
                (row[i] | liner[j] | gong[i / 3][j / 3]);
            int cnt = 0;
            for(int k = 0; k < 9; ++k){
                if(mask & (1 << k)) cnt++;
            }
            if(cnt == 0) return;    //说明没有可以填的位置
            if(cnt < minn){
                minn = cnt;
                x = i, y = j;
            }
        }
    }

    if(x == -1){
        flag = 1;
        return;
    }
    int mask = ((1 << 9) - 1) ^
           (row[x] | liner[y] | gong[x / 3][y / 3]);

    for(int i = 0; i < 9; ++i){
        int bit = 1 << i;
        if(!(mask & bit)) continue;

        //更新状态
        a[x][y] = '1' + i;
        row[x] |= bit;
        liner[y] |= bit;
        gong[x/3][y/3] |= bit;

        dfs();

        if(flag) return;    //一旦找到就返回

        //回溯
        a[x][y] = '.';
        row[x] ^= bit;
        liner[y] ^= bit;
        gong[x / 3][y / 3] ^= bit;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while(cin >> s && s != "end"){
        init();

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                a[i][j] = s[i*9+j];
            }
        }
        //行列
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if (a[i][j] != '.')
                    row[i] |= 1 << (a[i][j] - '1');
                if (a[j][i] != '.')
                    liner[i] |= 1 << (a[j][i] - '1');
            }
        }
        //九宫格
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                for(int k = i; k < i+3; ++k){
                    for(int l = j; l < j+3; ++l){
                        if(a[k][l] == '.') continue;
                        gong[i/3][j/3] |= 1<<(a[k][l]-'1');
                    }
                }
            }
        }
        //组合一起
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(a[i][j] == '.'){
                    hefa[i][j] = row[i] | liner[j] | gong[i/3][j/3];
                    hefa[i][j] ^= ((1<<9)-1);
                }
            }
        }

        dfs();
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cout << a[i][j];
            }
        }
        cout << "\n";
    }
        

    return 0;
}