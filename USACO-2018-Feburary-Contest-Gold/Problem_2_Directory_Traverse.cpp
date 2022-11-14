#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int L = 1e5 + 5;
LL n, leaf, ans;  // leaf:总的叶节点的个数  ans:所有文件的相对路径的长度之和的最小值
LL len[L], dis[L];  // len:文件夹或文件名字长度  dis:到根节点的路径长度
LL leafcnt[L], sum[L];  // leafcnt:叶节点的数目  sum:相对路径长度之和
vector<int> son[L];     // son:存子节点

// 求出从根节点到其他点的相关信息
void dfs1(int x)
{
    if (son[x].empty())
    {
        dis[x]--;
        leafcnt[x] = 1;
        sum[1] += dis[x];
    }
    else
    {
        for (int i : son[x])
        {
            dis[i] += dis[x] + len[i] + 1;
            dfs1(i);
            leafcnt[x] += leafcnt[i];
        }
    }
}

// 求答案
void dfs2(int x)
{
    for (int i : son[x])
    {
        if (!son[i].empty())
        {
            sum[i] = sum[x] - (len[i] + 1) * leafcnt[i] + 3 * (leaf - leafcnt[i]);
            ans = min(ans, sum[i]);
            dfs2(i);
        }
    }
}

int main()
{
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        LL m;
        string s;
        cin >> s;
        len[i] = s.length();
        cin >> m;

        if (m == 0)
            leaf++;
        
        else
            for (int j = 1; j <= m; j++)
            {
                int u;
                cin >> u;
                son[i].push_back(u);
            }
    }

    dfs1(1);
    ans = sum[1];

    dfs2(1);

    cout << ans << endl;

    return 0;
}