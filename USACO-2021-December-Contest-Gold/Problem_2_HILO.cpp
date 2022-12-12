#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int n;
set <int> s;
int inp[200001];
int p[200001];
int l[200001], r[200001];
int ans[200001];

void dfs(int root, int v)
{
    if (l[root] == 0)
    {
        ans[root - 1] = v / 2;
    }
    else
    {
        if (v % 2 == 0)
            dfs(l[root], v + 1);
        else
            dfs(l[root], v);
    }

    if (r[root] == 0)
    {
        if (v % 2 == 1)
            ans[root] = (v + 1) / 2;
        else
            ans[root] = v / 2;
    }
    else
    {
        if (v % 2 == 1)
            dfs(r[root], v + 1);
        else
            dfs(r[root], v);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> inp[i];
        p[inp[i]] = i;
    }

    s.insert(inp[1]);

    for (int i = 2; i <= n; i++)
    {
        auto it = s.lower_bound(inp[i]);
        int u = -1;

        if (it != s.end())
            u = *it;
        
        if (it != s.begin())
        {
            --it;
            if (u == -1 || p[u] < p[*it])
                u = *it;
        }

        if (inp[i] > u)
            r[u] = inp[i];
        else 
            l[u] = inp[i];
        
        s.insert(inp[i]);

        for (auto x : s)
            cout << x << " ";
        cout << endl;
        for (int x = 1; x <= n; x++)
            cout << l[x] << " " << r[x] << endl;
        cout << "-------\n";
    }

    // dfs(inp[1], 0);

    // for (int i = 0; i <= n; i++)
    //     cout << ans[i] << endl;

    return 0;
}