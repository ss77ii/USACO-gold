#include <bits/stdc++.h>
#include <iterator>
#include <tuple>
using namespace std;

int N;
vector <tuple<int, int, int> > edges;

int main()
{
    cin >> N;

    int a, v;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> v;
        edges.emplace_back(make_tuple(v, i, a));
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    

    return 0;
}
