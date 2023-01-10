#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define INF 1e17

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("snakes.in");
    ofstream fout("snakes.out");

    ll n, k;
    fin >> n >> k;
    ++k;

    vector<ll> snakes(n + 1);

    for (ll i = 1; i <= n; i++)
        fin >> snakes[i];

    ll costs[n + 1][n + 1];

    for (ll left = 1; left <= n; left++)
    {
        ll sum = 0; ll max_n = 0;
        for (ll right = left; right <= n; right++)
        {
            max_n = max(max_n, snakes[right]);
            sum += snakes[right];

            costs[left][right] = max_n  * (right - left + 1) - sum;
        }
    }

    vector <vector<ll> > dp(n + 1, vector <ll> (k + 1, INF));

    dp[0][0] = 0; // dp[num][net_change]

    for (ll nets = 1; nets <= k; nets++)
    {
        for (ll num = 1; num <= n; num++)
        {
            for (ll changed = 0; changed < num; changed++)
            {
                dp[num][nets] = min(dp[num][nets], dp[changed][nets - 1] + costs[changed + 1][num]);
            }
        }
    }

    cout << dp[n][k] << endl;
    fout << dp[n][k] << endl;

    return 0;
}
