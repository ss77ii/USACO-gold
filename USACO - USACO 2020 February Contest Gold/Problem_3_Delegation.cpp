//  Problem 3. Delegation

#include <bits/stdc++.h>

using namespace std;

int n;

vector <int> inmap[100002];
vector <int> sub_trees[100002];
int counts[100002];

void dfs(int cur, int fa)
{
	counts[cur] = 1;
	for (auto i : inmap[cur])
	{
		if (i == fa) continue;

		dfs(i, cur);
		counts[cur] += counts[i];
		sub_trees[cur].push_back(counts[i]);
	}

	if (counts[cur] != n) sub_trees[cur].push_back(n - counts[cur]);
}

bool check(int k)
{
	if ((n - 1) % k != 0) return false;

	int cur[100002] = {};
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		for (int t: sub_trees[i])
		{
			int z = t % k;
			if (z == 0) continue;
			if (cur[k - z] > 0)
			{
				cur[k - z]--;
				cnt--;
			}
			else
			{
				cur[z]++;
				cnt++;
			}
		}

		if (cnt != 0) return false;
	}

	return true;
}

int main()
{
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
	cin >> n;

	int temp1, temp2;
	for (int i = 1; i < n; i++)
	{
		cin >> temp1 >> temp2;

		inmap[temp1].push_back(temp2);
		inmap[temp2].push_back(temp1);
	}

	dfs(1, 0);

	cout << 1;
	for (int i = 2; i < n; i++)
	{
		if (check(i))
			cout << 1;
		else
			cout << 0;
	}

	cout << endl;

	return 0;
}