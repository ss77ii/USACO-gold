//  Problem 2. HILO

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200002;

int n;
int inp[MAXN];
int loc[MAXN];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	int last = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
		loc[inp[i]] = i;

		if (inp[i] < n)
		{

		}
		else
		{

		}
	}



	return 0;
}
