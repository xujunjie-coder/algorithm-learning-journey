#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct o {
    int x,y;
};
bool cmp(o yh1,o yh2) {
    return yh1.x<yh2.x;
}
void solve() {
    int n;cin >> n;
    vector<o> a (n);
    for (int i=0;i<n;++i) {
        cin >> a[i].x;
        a[i].y=i;
    }
    sort(a.begin(),a.end(),cmp);
    int pos=a[0].y,ans=1;
    for (int i=0;i<n;++i) {
        if (a[i].y<pos) {ans++;}
        pos=a[i].y;
    }
    cout << ans << '\n';
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;cin >> T;
    while (T--) solve();
    return 0;
}