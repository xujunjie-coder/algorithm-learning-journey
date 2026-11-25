#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

unordered_map<int,vector<int>> mpx;
unordered_map<int,vector<int>> mpy;
vector<pair<int,int>> vecx;

int n;
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        mpx[x].push_back(y);
        mpy[y].push_back(x);
        vecx.push_back({x,y});
    }
sort(vecx.begin(),vecx.end());
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int x1 = vecx[i].first;
            int y1 = vecx[i].second;
            int x2 = vecx[j].first;
            int y2 = vecx[j].second;
            //针对平行于x轴
            if(x1 == x2 && (y1+y2) % 2 == 0){
                int y3 = (y2+y1)/2;
                if(mpy.count(y3)){
                    vector<int> &arr1 = mpy[y3];
                    for(int num : arr1){
                        if(num != x1) ans++;
                    }
                }
            }
            //针对平行于y轴
            if(y1 == y2 && (x1+x2) % 2 == 0){
                int x3 = (x2+x1)/2;
                if(mpx.count(x3)){
                    vector<int> &arr2 = mpx[x3];
                    for(int num : arr2){
                        if(num != y1) ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}