//  Problem 1. Balanced Photo

#include <bits/stdc++.h>
using namespace std;

const int L = 100005;

struct node
{
    int high, num;
};

node cow[L];
int n, c[L], cowrank[L], ans;

bool cmp(node a, node b) { return a.high > b.high; }

int lowbit(int x) { return x & (-x); }

int getSum(int x)
{
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int main()
{
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cow[i].high);
        cow[i].num = i;
    }

    sort(cow + 1, cow + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        cowrank[cow[i].num] = i;

    for (int i = 1; i <= n; i++)
    {
        int lcnt = getSum(cowrank[i]);
        int rcnt = cowrank[i] - 1 - lcnt;
        if (lcnt > 2 * rcnt || rcnt > 2 * lcnt)
            ans++;

        update(cowrank[i], 1);
    }

    printf("%d", ans);
    return 0;
}