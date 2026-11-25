#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void solve() {
    vector<int> a(26);
    for (int i=0;i<26;++i) {
        cin >> a[i];
    }
    string s;cin >> s;
    long long ans=0,pos=0;
    for (int i=0;i<s.size();++i) {
        int tg=a[s[i]-'a'];
        int t1=max(tg-pos,pos-tg)*10;
        int t2=min(pos+(1000-tg),1000-pos+tg)*10+1;
        ans+=min(t1,t2);
        pos=tg;
    }
    cout << ans <<'\n';
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;cin >> T;
    while (T--) solve();
    return 0;
}