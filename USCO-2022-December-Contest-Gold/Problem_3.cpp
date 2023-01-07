#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
vector<int> a[100020];
vector<int> b;
int n, m, x, y;
int d[100020];
int f[100020];
int c[100020];
int v[100020];
long long z;

int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return;
	}
	c[y] += c[x];
	f[x] = y;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		//todo
        s.insert({d[i], i});
        f[i] = i;
        c[i] = 1;
	}

	while (s.size())
	{
        //todo
		int u = s.begin()->second;
        s.erase(s.begin());
        b.push_back(u);
        v[u] = true;

        for (auto i : a[u])
        {
            if (!v[i])
            {
                s.erase({d[i], i});
                d[i]--;
                s.insert({d[i], i});
            }
        }
	}

	memset(v, 0, sizeof v);
	for (int i = b.size() - 1; i >= 0; i--)
	{
		//todo
        v[b[i]] = true;
        long long cnt = 0;
        for (auto j : a[b[i]])
        {
            if (v[j])
            {
                U(b[i], j);
                cnt++;
            }
        }
        z = max(z, c[F(b[i])] * cnt);
	}

	printf("%lld\n", z);
	return 0;
}
