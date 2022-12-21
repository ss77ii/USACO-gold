// Problem_1_Bribing_Cows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
