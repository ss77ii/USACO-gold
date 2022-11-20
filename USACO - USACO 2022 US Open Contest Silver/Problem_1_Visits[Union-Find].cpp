//  Problem 1. Visits

#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
	vector<int> union_find;

	void init(int N)
	{
		union_find = vector<int>(N, -1);
	}

	int find(int x)
	{
		return union_find[x] < 0 ? x : union_find[x] = find(union_find[x]);
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y)
			return;
		if (union_find[x] > union_find[y]) swap(x, y);
		union_find[x] += union_find[y];
		union_find[y] = x;
	}

	bool same(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y)
			return true;
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<tuple<int, int, int>> edges;

	int a, v;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> v;
		edges.emplace_back(v, i, a - 1);
	}

	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges. end());

	long long ans = 0;

	UnionFind p;
	p.init(N + 1);

	for (auto [i, j, k] : edges)
	{
		if (!p.same(j, k))
		{
			p.merge(j, k);
			ans += i;
		}
	}

	cout << ans << endl;
}