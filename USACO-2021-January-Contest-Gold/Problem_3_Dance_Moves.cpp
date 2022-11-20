#include <bits/stdc++.h>
using namespace std;

int N, K, M;
vector <pair <int, int> > s[200002];
int position[200002], p_after[200002];
bool vis[200002];
int cnt[200002], res;
int q[200002], l, r;
int ans[200002];

void add(int x, int limit)
{
	for (auto p : s[x])
	{
		if (p.first > limit)
			return;
		else
		{
			cnt[p.second]++;
			if (cnt[p.second] == 1) res ++;
		}
	}
}

void del(int x, int limit)
{
	for (auto p : s[x])
	{
		if (p.first > limit)
			return;
		else
		{
			cnt[p.second]--;
			if (cnt[p.second] == 0) res--;
		}
	}
}

int main()
{
	cin >> N >> K >> M;

	for (int i = 0; i <= N; i++)
	{
		s[i].push_back({0, i});
		position[i] = i;
	}

	int a, b;
	for (int i = 1; i <= K; i++)
	{
		cin >> a >> b;
		s[position[a]].push_back({i, b});
		s[position[b]].push_back({i, a});
		swap(position[a], position[b]);
	}

	for (int i = 1; i <= N; i++)
		p_after[position[i]] = i;
	
	int t = M / K;
	int w = M % K;

	for (int i = 1; i <= N; i++)
	{
		if (vis[i])
			continue;
		
		bool cycle = false;
		l = 1, r= 0;

		for (int u = i, j = 1; j <= t; j++)
		{
			if (u == i && j != 1)
			{
				cycle = true;
				break;
			}

			add(u, K);
			q[++r] = u;
			u = p_after[u];
		}

		if (cycle)
		{
			ans[i] = res;
			vis[i] = true;
			del(i, K);
			for (int u = position[i]; u != i; u = p_after[u])
			{
				ans[u] = ans[i];
				vis[u] = true;
				del(u, K);
			}
		}
		
		else
		{
			p_after[0] = i;
			for (int u = i, j = 1; u != i || j == 1; u = p_after[u], j++)
			{
				int nxt = p_after[q[r]];
				add(nxt, w);
				ans[u] = res;
				del(nxt, w);
				add(nxt, K);
				del(u, K);

				l++;
				q[++r] = nxt;
				vis[u] = 1;
			}

			for (int j = 1; j <= r; j++)
			{
				del(q[j], K);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] << endl;
	}

	return 0;
}
