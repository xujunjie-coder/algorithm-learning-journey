#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int const N = 70;
int n;
int a[N];
bool used[N];   //记录哪些已经用过了
int sum;        //存总长度
int ans;
int tar;
int tar_len;
bool found;
void init(){
    memset(used,0,sizeof used);
    sum = 0;
    ans = 0;
    found = 0;
}

void dfs(int start,int cur_len, int fineshed){
    if(fineshed == tar) {
        found = 1;
        return;
    }
    int last = -1;
    for(int i = start; i < n; ++i){
        if(used[i] || cur_len + a[i] > tar_len) continue;
        if(last == a[i]) continue;
        used[i] = 1;
        if(cur_len + a[i] == tar_len){
            dfs(0,0,fineshed+1);
        }
        else{
            dfs(i+1,cur_len + a[i],fineshed);
        }
        used[i] = 0;    //尝试下一个
        if(found) return;
        last = a[i];
        if(cur_len == 0) return;    //尝试拼接空木
        if(cur_len + a[i] == tar_len) return;   //恰好补满却失败，不再换其他组合
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n && n){
        init();
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            sum += a[i];
            if(ans < a[i]) ans = a[i];
        }
        sort(a,a+n); reverse(a,a+n);
        for(int i = ans; i <= sum; ++i){    //枚举答案
            if(sum % i != 0) continue;
            tar = sum / i;
            tar_len = i;
            dfs(0,0,0);
            if(found){
                cout << i << '\n';
                break;
            }
        }
    }


    return 0;
}
