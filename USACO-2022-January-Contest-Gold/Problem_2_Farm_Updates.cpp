#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int n, q;
vector<int> b[N];
int f[N];
char o[N << 1];
int x[N << 1];
int d[N << 1];
int r[N << 1];
int e[N << 1][2];
int ans[N];
int ecnt;

int find(int x)
{
	if(f[x] == x)
	{
		return x;
	}
	f[x] = find(f[x]);
	return f[x];
}

void merge(int x, int y, int i)
{
    int fx = find(x);
    int fy = find(y);
    if (d[fx] != d[fy])
	{
        if (d[fx] == 0)
		{
            swap(fx, fy);
        }
        d[fx] = 0;
        for (int j : b[fx])
		{
            ans[j] = i;
        }
    }
    if (fx != fy)
	{
        if (b[fx].size() > b[fy].size())
		{
            swap(fx, fy);
        }
        for (int j : b[fx])
		{
            b[fy].push_back(j);
        }
        b[fx].clear();
        f[fx] = fy;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < q; i++)
	{
        cin >> o[i];
        if (o[i] == 'A')
		{
            ecnt++;
            cin >> e[ecnt][0] >> e[ecnt][1];
        }
		else
		{
            cin >> x[i];
            if (o[i] == 'R')
			{
                r[x[i]] = 1;
            }
			else // 'D'
            {
                d[x[i]] = 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
	{
        f[i] = i;
        b[i].push_back(i);
        if (d[i] == 0)
		{
            ans[i] = q;
        }
    }
    
    for (int i = 1; i <= ecnt; i++)
	{
        if (r[i] == 0)
		{
            merge(e[i][0], e[i][1], q);
        }
    }
    
    for (int i = q - 1; i >= 0; i--)
	{
        if (o[i] == 'R')
		{
            merge(e[x[i]][0], e[x[i]][1], i);
        }
		else if (o[i] == 'D')
		{
            int fx = find(x[i]);
            if (d[fx] == 1)
			{
                d[fx] = 0;
                for (int j : b[fx])
				{
                    ans[j] = i;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
	{
        cout << ans[i] << endl;
    }
    
    return 0;
}
