#include <bits/stdc++.h>
using namespace std;

int N;

struct FW_tree
{
    vector<int> bit;  // binary indexed tree
    int n;

    FW_tree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FW_tree(vector<int> a)
        : FW_tree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int a[200002];
long long ans;
int pre[200002];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    FW_tree x(N + 1);

    for (int i = 1; i <= N; i++)
    {
        ans += x.sum(i) - x.sum(pre[a[i]]);

        if (pre[a[i]] != 0)
            x.update(pre[a[i]], -1);
        
        pre[a[i]] = i;
        x.update(i, 1);
    }

    cout << ans << endl;

    return 0;
}
