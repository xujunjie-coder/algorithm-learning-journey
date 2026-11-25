#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

stack<int> st1,st2;

void Push(int x){
    if(st2.empty()){
        st2.push(x);
    }else{
        st2.push(min(x,st2.top()));
    }
    st1.push(x);
}

void Min(){
    cout << st2.top() << "\n";
}

void Pop(){
    st1.pop();
    st2.pop();
}

void Top(){
    cout << st1.top() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if(s == "min"){
            Min();
        }else if(s == "pop"){
            Pop();
        }else if(s == "top"){
            Top();
        }else{
            int x;
            cin >> x;
            Push(x);
        }
    }
    return 0;
}