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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    int ju = x / 5;
    cout << ju/2*3+(ju-ju/2)*4;

    return 0;
}