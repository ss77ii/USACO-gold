//  Problem 1. High Card Low Card (Gold)

#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
//    freopen("cardgame.in", "r", stdin);
//    freopen("cardgame.out", "w", stdout);

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    vector<bool> used(2 * N);
    vector<int>(A);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
        used[A[i]] = true;
    }

    sort(A.begin(), A.begin() + N / 2);
    sort(A.begin() + N / 2, A.end());
    rotate(A.begin(), A.begin() + N / 2, A.end());

    vector<int> B;

    for (int i = 0; i < 2 * N; i++)
        if (!used[i])
            B.push_back(i);

    int res = 0;

    for (int i = N / 2, j = N / 2; i < N; i++, j++, res++)
    {
        while (j < N && B[j] < A[i])
            j++;
        if (j == N)
            break;
    }

    for (int i = N / 2 - 1, j = N / 2 - 1; i >= 0; i--, j--, res++)
    {
        while (j >= 0 && B[j] > A[i])
            j--;
        if (j == -1)
            break;
    }

    cout << res << endl;

    return 0;
}
