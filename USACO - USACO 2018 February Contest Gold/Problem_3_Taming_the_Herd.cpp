//  Problem 3. Taming the Herd

#include <bits/stdc++.h>

using namespace std;

int a[102];
int cnt[102][102];
int dp[102][102];
int n;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			cnt[i][j] = cnt[i][j - 1] + (a[j] != (j - i));

	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;
	dp[1][1] = (a[1] != 0);

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = j; k <= i; k++)
				dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + cnt[k][i]);

	for (int i = 1; i <= n; i++)
		cout << dp[n][i] << endl;

	return 0;
}
