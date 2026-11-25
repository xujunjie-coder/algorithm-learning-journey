#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, x, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while(T--) {
        cin >> n >> x >> k;
        
        if(k < n) {
            cout << "NO\n";
            continue;
        }
        
        int tar = k - n;    
        
        if (tar == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i)  cout << x << (i == n - 1 ? "" : " ");
            cout << "\n";
            continue; 
        }
        vector<int> a; 
        for(int i = 1; i <= x; ++i) {
            a.push_back(x/i - 1); 
        }
        //Erase-Unique去重法
        sort(a.begin(), a.end());   //排序
        a.erase(unique(a.begin(), a.end()), a.end());
        //分两步，第一步是unique(a.begin(), a.end())，将重复的元素移动到最后，然后返回第一个重复且移到末尾的下标
        //第二步是a.erase(it, a.end())删去后面的重复的元素


        vector<int> dp(tar + 1, 1e9);  //j为额外权值，然后dp[j]为所需的元素个数  
        vector<int> pre(tar + 1, -1);    
        vector<int> choice(tar + 1, -1); 
        dp[0] = 0;
        for (int w : a) {
            for (int j = w; j <= tar; ++j) {
                if (dp[j - w] + 1 < dp[j]) {
                    dp[j] = dp[j - w] + 1;
                    pre[j] = j - w;
                    choice[j] = w; 
                }
            }
        }

        if (dp[tar] > n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> ans;
            int curr = tar;
            while (curr > 0) {
                int w = choice[curr];
                ans.push_back(x / (w + 1)); 
                curr = pre[curr];
            }
            
            while (ans.size() < n) {
                ans.push_back(x);
            }
            
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    
    return 0;
}