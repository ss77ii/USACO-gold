#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <limits.h>

using namespace std;

int n; // number of cows
int inp[102]; // input
int cnt[102][102]; // the number of mismatched data from day i to j
int dp[102][102]; // from 1 to i, there are j break outs.

int main()
{
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> inp[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int c = j - i;
			if (inp[j] != c)
				cnt[i][j] = cnt[i][j - 1] + 1;
			else
				cnt[i][j] = cnt[i][j - 1];
		}
	}
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = 1000000;
		}
	}

	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	dp[1][1] = (inp[1] != 0);
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = j; k <= i; k++)
			{
				dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + cnt[k][i]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << dp[n][i] << endl;
	}

	return 0;
}

