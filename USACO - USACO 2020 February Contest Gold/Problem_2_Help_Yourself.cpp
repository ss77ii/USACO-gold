//  Problem 2. Help Yourself

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

struct seg {
	int l, r;
} a[100005];

int s[200005];
ll f[100005];

bool cmp(const seg& b, const seg& c)
{
	return b.l < c.l;
}

inline ll fastpow(ll x, ll k)
{
	ll ans = 1;
	while (k)
	{
		if (k & 1)
			ans = (1LL * ans * x) % MOD;

		x = (1LL * x * x) % MOD;
		k >>= 1;
	}
	return ans;
}

int n;

int main()
{
//	freopen("help.in", "r", stdin);
//	freopen("help.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].l >> a[i].r;
		s[a[i].r]++;
	}
	
	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= 2 * n; i++)
		s[i] += s[i - 1];

	for (int i = 1; i <= n; i++)
	{
		f[i] = (2 * f[i - 1] + fastpow(2, s[a[i].l - 1])) % MOD;
	}

	cout << f[n] << endl;

	return 0;
}
