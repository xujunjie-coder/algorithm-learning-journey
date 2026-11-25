#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
stack<int> pre;
stack<int> suf;
int const N = 1e6+5;
ll f[N];
int cur = 1;
ll f_max[N];

void init(){
    f[0] = 0;
    f_max[0] = LLONG_MIN;
    cur = 1;
    while(!pre.empty()) pre.pop();
    while(!suf.empty()) suf.pop();
}

void solve(char ch){
    if(ch == 'I'){
        int x;
        cin >> x;
        pre.push(x);
        f[cur] = f[cur-1] + x;
        f_max[cur] = max(f_max[cur-1],f[cur]);
        cur++;
    }
    else if(ch == 'D'){
        if(!pre.empty()){
        pre.pop();
        cur--;
        }

    }else if(ch == 'L'){
        if(!pre.empty()){
            suf.push(pre.top());
            pre.pop();
            cur--;
        }

    }else if(ch == 'R'){
        if(!suf.empty()){
            pre.push(suf.top());
            f[cur] = f[cur-1]+suf.top();
            f_max[cur] = max(f_max[cur-1],f[cur]);
            cur++;
            suf.pop();
        }

    }else if(ch == 'Q'){
        int k;
        cin >> k;
        cout << f_max[k] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    while(cin >> q){
        init();
        while(q--){
            char ch;
            cin >> ch;
            solve(ch);
            // cerr << T << "\n";
            // cerr << ch << "\n";
            // if(pre.size()){
            //     cerr << "pre.top: " << pre.top() << "\n";
            // }
            // if(suf.size()){
            //     cerr << "suf.top: " << suf.top() << "\n";
            // }
            // cerr << "cur: " << cur << "\n";
            // cerr << "前缀和：" << f[cur-1] << "\n";
            // cerr << "\n";
        }
    }


    return 0;
}