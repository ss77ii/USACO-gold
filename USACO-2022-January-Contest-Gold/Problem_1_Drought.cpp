//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//int mod = 1000000007;
//int inp[102];
//int h = 1000000007;
//int f[1002][1002]; // f[i][j], i stands for the cows, j stands for the highest relative hunger level
//// which is basically h, and h is the smallest input.
//long long ans;
//
///*
//3
//9 11 7
//*/
//
//int main()
//{
//    cin >> n;
//
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> inp[i];
//        h = min(h, inp[i]);
//    }
//
//    for (int i = 0; i <= inp[1]; i++)
//        f[1][i] = i + 1;
//
//    if (n % 2 == 0)
//        h = 0;
//
//    for (int d = 0; d <= h; d++)
//    {
//        for (int i = 2; i <= n; i++)
//        {
//            f[i][0] = f[i - 1][min(inp[i], inp[i - 1]) - d];
//            for (int j = 1; j <= inp[i] - d; j++)
//            {
//                f[i][j] = (f[i][j - 1] + f[i - 1][min(inp[i] - j, inp[i - 1]) - d]) % mod;
//            }
//        }
//
//        ans = (ans + f[n][0]) % mod;
//    }
//
//    cout << ans;
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int n;
int hunger[1001];
int lowest_hunger = 100000;
int highest_hunger = -1;
long long dp[102][1002];
long long ans = 0;
long long mod = 1000000007;

int main()
{
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> hunger[i];
		lowest_hunger = min(lowest_hunger, hunger[i]);
		highest_hunger = max(highest_hunger, hunger[i]);
	}

	if (n % 2 == 0)
		lowest_hunger = 0;

	int t;

	int t2;
	
	for (int i = 0; i <= lowest_hunger; i++)
	{
		t = min(hunger[1], hunger[2]) - i;
		for (int i = 0; i <= highest_hunger; i++)
			dp[2][i] = min(i, t) + 1;
		
		for (int x = 3; x <= n; x++)
		{
			t = min(hunger[x], hunger[x - 1]) - i;
			dp[x][0] = dp[x - 1][hunger[x - 1] - i];
			
			for (int y = 1; y <= t; y++)
				dp[x][y] = (dp[x][y - 1] + dp[x - 1][hunger[x - 1] - y - i]) % mod;
			
			for (int y = t + 1; y <= highest_hunger; y++)
				dp[x][y] = dp[x][y - 1];
		}
		
		ans = (ans + dp[n][hunger[n] - i]) % mod;
	}
	
	cout << ans << endl;
	
	return 0;
}

