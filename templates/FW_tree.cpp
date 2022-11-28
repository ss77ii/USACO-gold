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
