//  Problem 2. HILO

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, p[200001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int x = 0; x <= n; x++)
	{
		int mn = 0, mx = n + 1, ans = 0;
		bool hi = false;
		for (int i = 0; i < n; i++)
		{
			if (p[i] > mx || p[i] < mn) continue;
			if (p[i] > x)
			{
				hi = true;
				mx = p[i];
			}
			else
			{
				ans += hi;
				hi = false;
				mn = p[i];
			}
		}

		cout << ans << endl;
	}
	return 0;
}
