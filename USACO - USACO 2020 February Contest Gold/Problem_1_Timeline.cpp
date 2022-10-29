//  Problem 1. Timeline

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
int N, M, C;
int dis[MAXN];
int d[MAXN];
vector<pair<int, int> > g[MAXN];
queue<int> q;

/*
差分约束系统
对于每个三元组 (a,b,x)，从a向b连一条长度为x的边。同时新建一个超级源点0，
从0向i连长度为si的边。容易发现这张图是一个 DAG，利用拓扑排序计算即可。
*/
int main()
{
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);

	scanf("%d %d %d", &N, &M, &C);

	for (int i = 1; i <= N; i++)
		scanf("%d", dis + i);

	int u, v, w;
	for (int i = 1; i <= C; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back( v, w );
		d[v] += 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		for (auto e : g[f])
		{
			dis[e.first] = max(dis[e.first], dis[f] + e.second);
			if (--d[e.first] == 0)
				q.push(e.first);
		}
	}

	for (int i = 1; i <= N; i++)
		printf("%d\n", dis[i]);
	
	return 0;
}