#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[402];
int dp[402][402];

int cnt[402][402];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j <= k; j++)
            dp[i][j] = 0x3f;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cnt[i][i] = 0;
        int Max = a[i], sum = a[i], count = 1;
        for (int j = i + 1; j <= n; j++)
        {
            sum += a[j];
            Max = max(Max, a[j]);
            count++;
            cnt[i][j] = (Max * count - sum);
        }
    }

    dp[1][1] = 0;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = j - 1; x > 1; x--)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][x - 1] + cnt[x][j]);
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
