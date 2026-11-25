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
        priority_queue<int> low;  // 大根堆
        priority_queue<int,vector<int>,greater<int>> high;   //小根堆存后部分M/2+1~M
        //默认大根堆多一个，取顶部就是中位数
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            int x;
            cin >> x;
            if(high.empty() || x >= high.top()){
                high.push(x);
            }else{ low.push(x);}

            if(high.size()  > low.size() + 1){
                low.push(high.top());
                high.pop();
            }else if(low.size() > high.size()){
                high.push(low.top());
                low.pop();
            }
            if(i % 2 == 1) {
                cout << high.top() << " ";
                cnt++;
                if(cnt % 10 == 0)cout << "\n";
            }
            
        }
        if (cnt % 10 != 0) cout << "\n";
    }

    return 0;
}