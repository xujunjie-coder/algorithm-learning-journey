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
int const N = 2e5+5;
int n;
string s;

int prefA[N];
int prefB[N];
int stuffA[N]; 
int stuffB[N];

// 修正后的正向预处理：求 a 的前缀中，是 b 的子序列的最长连续子串
void get_pref(string a, string b, int pref[]){
    int lena = a.size();
    int lenb = b.size();
    // L[i][j] 表示以 a[i-1] 结尾的连续子串中，能匹配 b[0...j-1] 的最长长度
    vector<vector<int>> L(lena + 1, vector<int>(lenb + 1, 0));
    pref[0] = 0; 
    for(int i = 1; i <= lena; ++i){
        for(int j = 1; j <= lenb; ++j){
            if(a[i-1] == b[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                // 关键点：如果不相等，原串连续性在这里断开！
                // 只能继承目标串少看一位的历史记录，不能继承原串的历史记录
                L[i][j] = L[i][j-1]; 
            }
        }
        // pref[i] 记录整个前缀 a[0...i-1] 范围内的历史最高分
        pref[i] = max(pref[i-1], L[i][lenb]);
    }
}

// 修正后的逆向预处理：求 a 的后缀中，是 b 的子序列的最长连续子串
void get_suff(string a, string b, int suff[]){
    int lena = a.size();
    int lenb = b.size();
    // R[i][j] 表示以 a[i] 开头的连续子串中，能匹配 b[j...lenb-1] 的最长长度
    vector<vector<int>> R(lena + 1, vector<int>(lenb + 1, 0));
    suff[lena] = 0; 
    for(int i = lena - 1; i >= 0; --i){
        for(int j = lenb - 1; j >= 0; --j){
            if(a[i] == b[j]) {
                R[i][j] = R[i+1][j+1] + 1;
            } else {
                // 同样，不相等则说明右边连续性断开，只能往目标词后方继承
                R[i][j] = R[i][j+1];
            }
        }
        // suff[i] 记录整个后缀 a[i...lena-1] 范围内的历史最高分
        suff[i] = max(suff[i+1], R[i][0]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    if (!(cin >> n >> s)) return 0;
    
    get_pref(s, "greet", prefA);
    get_pref(s, "invite", prefB);
    get_suff(s, "greet", stuffA);
    get_suff(s, "invite", stuffB);

    int maxans = 0;
    // 枚举切口 i
    for(int i = 0; i <= n; ++i){
        int tmp = max(prefA[i] + stuffB[i], prefB[i] + stuffA[i]);
        maxans = max(maxans, tmp);
    }
    
    // 总目标长度 11 - 最大可保留的连续有效字符
    cout << 11 - maxans << endl;
    
    return 0;
}