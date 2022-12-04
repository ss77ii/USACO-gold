#include <bits/stdc++.h>
using namespace std;

int t;
int MOD = 1000000007;

string get()
{
    string s, d;
    cin >> s;
    for (auto c : s)
    {
        if (c == '0')
        {
            d = "0";
        }
        else if (c != '1')
        {
            d += c;
        }
    }
    return d;
}

int f[2005][2005];
int g[2005][2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> t;

    int n;
    string x, y;
    for (int a = 1; a <= t; a++)
    {
        cin >> n;

        x = get();
        y = get();

        int ans = 0;

        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));

        f[1][0] = 1;
        g[0][1] = 1;

        for (int i = 0; i <= x.size(); i++)
        {
            for (int j = 0; j <= y.size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;

                if (i <= x.size())
                {
                    f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
                    if (j > 0 && y[j - 1] != '+' && x[i] == '+')
                        f[i + 1][j] = (f[i + 1][j] + g[i][j]) % MOD;
                    if (j > 0 && y[j - 1] == '+' && x[i] != '+')
                        f[i + 1][j] = (f[i + 1][j] + g[i][j]) % MOD;
                }

                if (j <= y.size())
                {
                    g[i][j + 1] = (g[i][j + 1] + g[i][j]) % MOD;
                    g[i][j + 1] = (g[i][j + 1] + f[i][j]) % MOD;
                }
            }
        }

        ans = (f[x.size()][y.size()] + g[x.size()][y.size()]);

        cout << (ans % MOD) << endl;
    }

    return 0;
}

