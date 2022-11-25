#include <bits/stdc++.h>
using namespace std;

class Union_Find // required for kruskal
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
        int countn(int x) // the number declared set will influence value, if entered 6 but only used 4 and they are all in one set, value would be 1 + 2 = 3 rather than 1.
        { // x stands for if it starts at 1 or 0
            return cnt - x;
        }
};
 
class MST_graph // the graph class
{
    vector<vector<int> > graph;
    int V;
 
    public:
        MST_graph(int V) { this -> V = V; }
    
        void addEdge(int a, int b, int w) // first point a connecting to second point b with weight w
        {
            graph.push_back({ w, a, b });
        }
    
        long long kruskal_mst() // kruskal program for minimum spanning tree
        {
            // First: Sort all edges based on weight
            sort(graph.begin(), graph.end());
    
            // Start Union_Find, we use Union_Find to detect any cycle that may occur after adding a new edge
            Union_Find s(V);

            long long ans = 0;
            for (auto cur : graph)
            {
                int w = cur[0];
                int a = cur[1];
                int b = cur[2];

                if (s.find(a) != s.find(b)) // as long as don't form a cycle
                {
                    s.merge(a, b); // push back the edge
                    ans += w; // add weight to the answer
                }
            }

            return ans; // return te answer
        }
};

int n;

int main()
{
    cin >> n;

    MST_graph x(200002);

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;

        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        x.addEdge(a1, a2, 0);
        x.addEdge(b1, b2, 0);
        x.addEdge(a1, b2, c);
    }

    long long ans = x.kruskal_mst();
    cout << ans << endl;

    return 0;
}
