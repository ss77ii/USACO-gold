//  Problem 3. Why Did the Cow Cross the Road III

#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n;
int sum;
int c[MAXN];

struct node
{
    int l, r;
} a[MAXN];

/**
 * The above function is used to calculate the sum of the first x elements in an array.
 *
 * @param x the index of the element to be updated
 *
 * @return The number of elements in the array that are less than or equal to the given number.
 */
int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int k)
{
    for (int i = x; i <= n * 2; i += lowbit(i))
        c[i] += k;
}

int getSum(int x)
{
    int x_sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        x_sum += c[i];
    return x_sum;
}

bool cmp(const node& x, const node& y)
{
    return x.l < y.l;
}

int main()
{
//	freopen("circlecross.in", "r", stdin);
//	freopen("circlecross.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n * 2; i++)
    {
        int x;
        cin >> x;

        if (a[x].l == 0)
            a[x].l = i;

        else
            a[x].r = i;
    }

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
    {
        sum += getSum(a[i].r) - getSum(a[i].l - 1);
        update(a[i].r, 1);
    }

    cout << sum << endl;

    return 0;
}
