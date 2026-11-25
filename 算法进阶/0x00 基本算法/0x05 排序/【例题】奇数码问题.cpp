#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int n;
int const N = 500;
int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n && n){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }
        
    }

    return 0;
}