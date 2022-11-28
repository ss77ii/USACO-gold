#include <bits/stdc++.h>
using namespace std;

int n;
int mod = 1000000007;
int inp[102];
int h = 1000000007;
int f[1002][1002]; // f[i][j], i stands for the cows, j stands for the highest relative hunger level
// which is basically h, and h is the smallest input.
long long ans;

/*
3
9 11 7
*/

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> inp[i];
        h = min(h, inp[i]);
    }

    for (int i = 0; i <= inp[1]; i++)
        f[1][i] = i + 1;
    
    if (n % 2 == 0)
        h = 0;
    
    for (int d = 0; d <= h; d++)
    {
        for (int i = 2; i <= n; i++)
        {
            f[i][0] = f[i - 1][min(inp[i], inp[i - 1]) - d];
            for (int j = 1; j <= inp[i] - d; j++)
            {
                f[i][j] = (f[i][j - 1] + f[i - 1][min(inp[i] - j, inp[i - 1]) - d]) % mod;
            }
        }

        ans = (ans + f[n][0]) % mod;
    }

    cout << ans;

    return 0;
}
