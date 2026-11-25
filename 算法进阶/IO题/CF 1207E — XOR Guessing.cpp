#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int ask(bool flag){
    cout << "?";
    for(int i = 0; i < 100; ++i){
        int value;
        if(flag){   //高7位
            value = (127 << 7) | i;
        }else{
            value = (i << 7) | 127;
        }
        cout << " " << value;
    }
    cout << endl;
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a1 = ask(1);
    int a2 = ask(0);
    int high = (a1 >> 7) ^ 127; //先有移动7位，去除后7位影响以后再异或回去
    high <<= 7;                 //然后重新回到前7位
    int low = (a2 & 127) ^ 127; //先与后七位的1，高位自动归零，然后异或回去
    int x = high | low;         //二者拼接
    cout << "! " << x << endl;
    

    return 0;
}