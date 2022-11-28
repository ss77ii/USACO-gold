#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[100002];
int inp[100002];

int main()
{
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> inp[i];
	
	dp[1] = inp[1];
	
	for (int i = 2; i <= n; i++)
	{
		int mx = inp[i];
		for (int j = 0; j < k && (i - j - 1 >= 0); j++)
		{
			mx = max(inp[i - j], mx);
			dp[i] = max(dp[i], dp[i - j - 1] + mx * (j + 1));
		}
	}
	
	cout << dp[n];
	
	return 0;
}

