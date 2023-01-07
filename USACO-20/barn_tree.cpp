#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector <ll> x(200005);
vector <ll> r[200005];
vector <pair<ll, ll> > Edges[200005];
vector <ll> in_degree(200005);
ll avr = 0;
ll min_steps = 0;

void dfs_1(ll cur, ll fa)
{
    if (r[cur].size() != 0)
    {
        for (auto i : r[cur])
        {
            if (i != fa)
                dfs_1(i, cur);
        }
    }

    ll cur_val = x[cur];

    if (cur_val == avr)
        return;

    if (cur_val < avr)
    {
        Edges[fa].push_back({cur, abs(cur_val - avr)});
        in_degree[cur]++;
        min_steps++;
    }
    if (cur_val > avr)
    {
        Edges[cur].push_back({fa, abs(cur_val - avr)});
        in_degree[fa]++;
        min_steps++;
    }

    x[fa] += (cur_val - avr);
    x[cur] = avr;
}

int main()
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x[i];
        avr += x[i];
    }
    avr = avr / n;
    
    ll a, b;
    for (ll i = 1; i < n; i++)
    {
        cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    
    dfs_1(1, 0);

    cout << min_steps << endl;
    
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        ll temp = q.front();
        q.pop();

        if (Edges[temp].size() > 0)
        {
            for (int i = 0; i < Edges[temp].size(); i++)
            {
                cout << temp << " " << Edges[temp][i].first << " " << Edges[temp][i].second << endl;
                if (--in_degree[Edges[temp][i].first] == 0)
                {
                    q.push(Edges[temp][i].first);
                }
            }
        }
    }

    return 0;
}

/*

4
2 1 4 5
1 2
2 3
2 4

5
2 3 10 1 4
1 3
2 4
4 5
1 2

*/
