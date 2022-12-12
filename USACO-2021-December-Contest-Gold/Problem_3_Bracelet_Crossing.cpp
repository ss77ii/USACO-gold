#include <bits/stdc++.h>
using namespace std;

vector<int> outer;
vector<int> inner;
vector<int> endings;

int t;
int n, m;

bool solve()
{
    while(!outer.empty()) outer.pop_back();
    while(!inner.empty()) inner.pop_back();
    while(!endings.empty()) endings.pop_back();

    cin >> n >> m;
    vector <int> inp;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        for (int j = 1; j <= a; j++)
        {
            cin >> b;
            inp.push_back(b);
        }
    }

    

    return true;
}

int main()
{
    cin >> t;

    bool ans;
    for (int i = 0; i < t; i++)
    {
        ans = solve();
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
