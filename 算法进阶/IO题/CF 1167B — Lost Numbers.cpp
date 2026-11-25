#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int ask(int i,int j){
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    if(res == 0) exit(0);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = { 4,8,15,16,23,42 };

    int p12 = ask(1,2);
    int p23 = ask(2,3);
    int p45 = ask(4,5);
    int p56 = ask(5,6);
    do{
        if(a[0] * a[1] == p12 && a[1] * a[2] == p23 && a[3] * a[4] == p45 && a[4] * a[5] == p56){
            cout << "!";
            for(int i = 0; i < 6; ++i){
                cout << " " << a[i];
            }
            cout << endl;
        }
    }while(next_permutation(a.begin(),a.end()));
    

    return 0;
}