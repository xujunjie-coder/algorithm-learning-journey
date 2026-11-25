#include <iostream>
using namespace std;

int main()
{
    long long l = 1, r = 1e9;
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        cout << "? " << mid << endl; 
        int res;
        cin >> res;
        if(res == 0)
        {
            cout << "! " << mid << endl;
            break;
        }
        else if(res == -1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return 0;
}
