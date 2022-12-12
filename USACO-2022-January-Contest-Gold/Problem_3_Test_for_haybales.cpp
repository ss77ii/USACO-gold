// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// vector<int> T[N];
// int dep[N], x[N], now, maxdepth;

// void dfs(int u, int depth)
// {
//     dep[u] = depth;
//     x[u] = now--;
//     for (auto v : T[u])
//     {
//         dfs(v, depth + 1);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int n;
//     cin >> n;
//     for (int i = 1, j; i <= n; ++i)
// 	{
//         cin >> j;
//         T[j + 1].push_back(i);
//     }

//     for (int i = 1; i <= n + 1; ++i)
// 	{
//         sort(T[i].begin(), T[i].end(), greater<int>());
//     }

//     now = n + 1;
//     dfs(n + 1, 0);
//     for (int i = 1; i <= n + 1; ++i)
// 	{
//         maxdepth = max(maxdepth, dep[i]);
//     }

//     int k = n + 1;
//     cout << k << endl;
//     for (int i = 1; i <= n; ++i)
// 	{
//         cout << 1LL * (maxdepth - dep[i]) * k + x[i] << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
