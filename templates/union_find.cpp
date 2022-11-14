#include <bits/stdc++.h>
using namespace std;

int N;

class Union_Find
{
    int *id, cnt, *sz;
    public:
        // Create an empty union find data structure with N isolated sets.
        Union_Find(int N)
        {
            cnt = N;
            id = new int[N];
            sz = new int[N];
            for (int i = 0; i<N; i++)
                id[i] = i, sz[i] = 1;
        }
        ~Union_Find() { delete[] id; delete[] sz; }

        // Return the id of component corresponding to object v.
        int find(int v)
        {
            int parent = v;

            while (parent != id[parent])
                parent = id[parent];

            while (v != parent)
            {
                int nep = id[v];
                id[v] = parent;
                v = nep;
            }
            return parent;
        }

        // Replace sets containing v1 and v2 with their union. It would combine two sets or add value into one set.
        void merge(int v1, int v2)
        {
            int fx = find(v1);
            int fy = find(v2);

            if (fx == fy)
                return;
            if (sz[fx] < sz[fy])
                id[fx] = fy, sz[fy] += sz[fx];
            else
                id[fy] = fx, sz[fx] += sz[fy];

            cnt--;
        }
        // check if objects x and y are in the same set.
        bool connect(int v1, int v2)
        {
            return find(v1) == find(v2);
        }
        // Return the number of disjoint sets.
        int countn() // the number declared set will influence value, if entered 6 but only used 4 and they are all in one set, value would be 1 + 2 = 3 rather than 1.
        {
            return cnt;
        }
};

int main()
{
    cin >> N;
    Union_Find uf(N);

    uf.merge(1, 2);
    uf.merge(3, 4);

    cout << uf.find(4) << endl;
    cout << uf.countn() << endl;
    cout << uf.connect(1, 4) << endl;

    return 0;
}
