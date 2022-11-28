#include <bits/stdc++.h>
using namespace std;

int N, B[100001];
pair<int,int> inp[100001];

void modify(int j) { for (int j; j <= N; j += ( j & -j)) B[j]++; }
int prefix_sum(int j) { int sum = 0; for (int j; j > 0; j -= (j &- j)) sum += B[j]; return sum; }

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int answer = 1;
	cin >> N;
	
	for (int i=1; i<=N; i++)
	{
		int x;
		cin >> x;
		inp[i] = make_pair(x, i);
	}
	
	sort (inp + 1, inp + N + 1);
	
	for (int i = 1; i <= N - 1; i++)
	{
		modify(inp[i].second);
		answer = max(answer, i - prefix_sum(i));
	}

	cout << answer << endl;
	return 0;
}

