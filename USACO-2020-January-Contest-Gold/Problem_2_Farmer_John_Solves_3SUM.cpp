#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int OFFSET = 1e6;

int a[10005];
int cnt[2000005];
LL f[5005][5005]; // 注意long long

/*
区间DP
f[i][j]表示i~j的 3SUM 数量，这是一个区间 dp
根据容斥原理，得出f[i][j]=f[i+1][j]+f[i][j-1]-f[i+1][j-1]+p[i][j]
其中p[i][j]表示[i+1, j-1]这个区间的k的数量，满足ai+ak+aj=0
*/
int main()
{
    // freopen("threesum.in", "r", stdin);
    // freopen("threesum.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
	{
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++)
	{
		// 把cnt组数清零， cnt数组记录[i, j]区间内每个数出现的次数
		for (int j = 0; j <= n; j++)
			cnt[a[j] + OFFSET] = 0;

		for (int j = i + 1; j <= n; j++)
		{
			int ak = -a[i] - a[j];
			if (ak >= - OFFSET && ak <= OFFSET)
				f[i][j] = cnt[ak + OFFSET];
			
			cnt[a[j] + OFFSET]++;
		}
    }

    for (int i = n - 1; i >= 1; i--)
	{
        for (int j = i + 1; j <= n; j++)
		{
            f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
        }
    }

    for (int i = 1; i <= q; i++)
	{
        int l, r;
        cin >> l >> r;
        cout << f[l][r] << endl;
    }

    return 0;
}
