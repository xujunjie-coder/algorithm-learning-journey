#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> P;
    while(P--){
        int num,n;
        cin >> num >> n;
        cout << num << " " << (n+1)/2 << "\n";
        vector<int> a;
        priority_queue<int> low;  // 大根堆
        priority_queue<int,vector<int>,greater<int>> high;   //小根堆存后部分M/2+1~M
        //默认大根堆多一个，取顶部就是中位数
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            int x;
            cin >> x;
            if(low.empty() || x <= low.top()) low.push(x);
            else high.push(x);
            if(low.size() > high.size() + 1){
                high.push(low.top());
                low.pop();
            }else if(high.size() > low.size()){
                low.push(high.top());
                high.pop();
            }
            if(i % 2 == 1){
                if (cnt % 10 != 0) cout << " ";
                cout << low.top();
                cnt++;
                if(cnt % 10 == 0) cout << "\n";
            }
        }
        if (cnt % 10 != 0) cout << "\n";
    }

    return 0;
}