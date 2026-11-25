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
string s;
int const N = 1000010;
ull f1[N],p1[N];  //双哈希用131，13331进制
int q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //预处理
    cin >> s;
    s = " " + s;
    int n = s.length()+1;
    p1[0] = 1;
    for(int i = 1; i <= n; ++i){
        f1[i] = f1[i-1] * 131 + (s[i] - 'a' + 1);
        //f2[i] = f2[i-1] * 13331 + (s[i] - 'a' + 1);
        p1[i] = p1[i-1] * 131;
        //p2[i] = p2[i-1] * 13331;
    }
    cin >> q;
    int l1,r1,l2,r2;
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(f1[r1]-f1[l1-1]*p1[r1-l1+1] == f1[r2]-f1[l2-1]*p1[r2-l2+1]){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }

    }

    return 0;
}