#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
int T;
vector<vector<int>> a;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int max_n = n * m;
        a.assign(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int x;
                cin >> x;
                a[i][j] = x;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            bool flag = 0;
            for (int i = 0; i < 4; ++i)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                if (a[xx][yy] == max_n)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << "First\n";
                continue;
            }
            int step = 0;
            int x1 = x;
            int y1 = y;
            while (1)
            {
                int f = 0;
                for (int i = 0; i < 4; ++i)
                {
                    int xx = x1 + dx[i];
                    int yy = y1 + dy[i];

                    if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                        continue;
                    if (a[xx][yy] > a[x1][y1])
                    {
                        x1 = xx;
                        y1 = yy;
                        step++;
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                    break;
            }
            if (step % 2 == 0)
            {
                cout << "Second\n";
            }
            else
            {
                cout << "First\n";
            }
        }
    }
    return 0;
}