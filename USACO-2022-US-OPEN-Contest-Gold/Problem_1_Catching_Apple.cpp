#include <bits/stdc++.h>
using namespace std;

/*
cow: event i
apple: event j

ti <= tj  && abs(xi-xj) <= tj-ti


xi - xj <= tj - ti -> xi + ti <= xj + tj 
xj - xi <= tj - ti -> xj - tj <= xi - ti

P(xi-ti, xi+ti)
*/

int N, ans;
struct item
{
    int q, t, x, n;
} p[200001];

map<int, int> mp;

bool cmp(const item &a, const item &b)
{
	if (a.x - a.t != b.x - b.t)
	{
        return a.x - a.t < b.x - b.t;
	}
    return a.q > b.q;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i].q >> p[i].t >> p[i].x >> p[i].n;
	}
	
	sort(p + 1, p + 1 + N, cmp);
	
//	for (int i = 1; i <= n; i++)
//	{
//		cout << p[i].n << " " << p[i].t << " " << p[i].x << " " << p[i].n << endl;
//	}
	
	int temp_n = 0;
	
	for (int i = 1; i <= N; i++)
	{
		if (p[i].q == 1)
		{
			temp_n = p[i].n;

			while(temp_n > 0)
			{
				map<int, int>::iterator it = mp.lower_bound(p[i].x + p[i].t);
				if (it == mp.end())
					break;
				int u = min(temp_n, it->second);
				if (u == it->second)
                    mp.erase(it);
                else
                    it->second -= u;
                    
                temp_n -= u;
                ans += u;
			}
		}
		
		else
		{
			mp[p[i].x + p[i].t] += p[i].n;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

