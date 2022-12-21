#include <bits/stdc++.h>
using namespace std;

struct cows
{
    int p, c, x;
};

bool cmp(cows a, cows b)
{
    return a.x < b.x;
}

int ice_cones[2005][2005];
int mooney[2005][2005];

int main()
{
    int N, A, B;

    cin >> N >> A >> B;
    vector <cows> c(N);

    for (int i = 0; i < N; i++)
        cin >> c[i].p >> c[i].c >> c[i].x;
    
    sort(c.begin(), c.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            ice_cones[i + 1][j] = ice_cones[i][j];
            if (j >= c[i].x * c[i].c)
            {
                ice_cones[i + 1][j] = max(ice_cones[i + 1][j], ice_cones[i][j - c[i].c * c[i].x] + c[i].p);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j <= A; j++)
        {
            mooney[i][j] = mooney[i + 1][j];
            if (j >= c[i].c)
                mooney[i][j] = max(mooney[i][j], mooney[i + 1][j - c[i].c] + c[i].p);
        }
    }

    int v = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= c[i].c && j <= A; j++)
            if (B - (c[i].c - j) * c[i].x >= 0)
                v = max(v, mooney[i + 1][A - j] + ice_cones[i][B - (c[i].c - j) * c[i].x] + c[i].p);

    cout << v << endl;

    return 0;
}
