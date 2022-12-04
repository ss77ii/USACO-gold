#include <iostream>
#include <vector>
using namespace std;

long long n, m;
long long dp[302][302];

struct course
{
    long long pre_req, value;
};
vector <course> graph(302);
vector <vector <long long> > sons(302);

void dfs(long long root)
{
    dp[root][1] = graph[root].value;

    for (auto i : sons[root])
    {
        dfs(i);

        for (long long j = m; j >= 1; j--)
            for (long long k = j - 1; k >= 1; k--)
                dp[root][j] = max(dp[root][j], dp[root][j - k] + dp[i][k]);
    }
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (long long i = 1; i <= n; i++)
    {
        cin >> graph[i].pre_req >> graph[i].value;
        sons[graph[i].pre_req].push_back(i);
    }

    m++;
    dfs(0);
    cout << dp[0][m] << endl;

    return 0;
}
