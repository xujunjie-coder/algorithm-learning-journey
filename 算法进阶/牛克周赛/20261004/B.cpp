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
char a[5][5];

bool win(){
    for(int i = 1; i <= 3; ++i){
        if(a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][3] == '1') return 1;
    }
    for(int j = 1; j <= 3; ++j){
        if(a[1][j] == a[2][j] && a[2][j] == a[3][j] && a[3][j] == '1') return 1;
    }
    if(a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[3][3] == '1') return 1;
    if(a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[3][1] == '1') return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i < 4; ++i){
        for(int j = 1; j < 4; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < 4; ++i){
        for(int j = 1; j < 4; ++j){
            if(a[i][j] == '*'){
                a[i][j] = '1';
                if(win()){
                    cout << "Yes" << "\n";
                    cout << i << " " << j;
                    return 0;
                }
                a[i][j] = '*';
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}