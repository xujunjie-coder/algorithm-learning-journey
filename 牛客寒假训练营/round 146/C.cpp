#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

unordered_map<int,unordered_set<int>> mpx;
unordered_map<int,unordered_set<int>> mpy;
vector<pair<int,int>> vecx;

int n;
long long ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        mpx[x].insert(y);
        mpy[y].insert(x);
        vecx.push_back({x,y});
    }
sort(vecx.begin(),vecx.end());
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int x1 = vecx[i].first;
            int y1 = vecx[i].second;
            int x2 = vecx[j].first;
            int y2 = vecx[j].second;
            // 针对竖直底边（x 相同）: 只有当 y1+y2 为偶数时存在整点中点
            if(x1 == x2){
                if(((y1 + y2) & 1) == 0){
                    int y3 = (y2 + y1) / 2;
                    if(mpy.count(y3)){
                        unordered_set<int> &arr1 = mpy[y3];
                        int len = (int)arr1.size();
                        ans += len;
                        if(len && arr1.count(x1)) ans--;
                    }
                }
            }
            // 针对水平底边（y 相同）: 只有当 x1+x2 为偶数时存在整点中点
            if(y1 == y2){
                if(((x1 + x2) & 1) == 0){
                    int x3 = (x2 + x1) / 2;
                    if(mpx.count(x3)){
                        unordered_set<int> &arr2 = mpx[x3];
                        int len = (int)arr2.size();
                        ans += len;
                        // arr2 存的是该列的 y 值，应该检查是否包含底边的 y1
                        if(len && arr2.count(y1)) ans--;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}