#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int n; int q;
ll bitmask[(1 << 20) + 1][21];
int pos[21];

int main()
{
    cin >> n;

    vector<int> pref(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> pref[j];

        for (auto p : pref)
        {
            pos[i] |= 1 << p;

            cout << pos[i] << " ";

            if (p == i)
                break;
        }

        cout << endl;
    }

//    cin >> q;
//
//    for (int i = 1; i <= q; i++)
//    {
//
//    }

    return 0;
}
