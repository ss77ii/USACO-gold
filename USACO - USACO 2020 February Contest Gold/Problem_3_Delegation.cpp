//  Problem 3. Delegation

#include <bits/stdc++.h>

using namespace std;

int n;
int k = 3;

vector <int> maps[100002];

int dfs(int cur, int fa)
{
	if (maps[cur][0] == fa && maps[cur].size() == 1)
		return 0;

	else
	{
		vector <int> l;
		int x;

		for (auto i : maps[cur])
		{
			if (i != fa)
			{
				x = dfs(i, cur);

				l.push_back(x);
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	int temp1, temp2;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> temp1 >> temp2;

		maps[temp1].push_back(temp2);
		maps[temp2].push_back(temp1);
	}

	cout << dfs(1, 0);

	return 0;
}
