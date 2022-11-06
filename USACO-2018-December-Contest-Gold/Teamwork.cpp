#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int inp[10002];
int dp[10002];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> inp[i];
    
    dp[1] = inp[1];

    for (int i = 2; i <= n; i++)
    {
        int Max = inp[i];
        for (int j = i; j >= 1 && (i - j + 1 <= k); j--)
        {
            Max = max(Max, inp[j]);
            dp[i] = max(dp[i], dp[j - 1] + Max * (i - j + 1));
        }
    }

    cout << dp[n] << endl;

    return 0;
}
