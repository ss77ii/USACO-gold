//  Problem 1. Snow Boots

#include <bits/stdc++.h>

using namespace std;
#define MAXN 100000
#define MAXB 100000

/**
 * It sets the standard input and output streams to the files with the given name
 *
 * @param s the name of the input file
 */
void setIO(const string& s)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int N, B;
int depth[MAXN];
int did[MAXN];

bool dcmp(int a, int b)
{
	return depth[a] < depth[b];
}

int snow[MAXB], dist[MAXB];
int ans[MAXB];
int bid[MAXB];

bool s_bcmp(int a, int b)
{
	return snow[a] < snow[b];
}

int nxt[MAXN];
int pre[MAXN];

int main()
{
//	setIO("snowboots");
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		cin >> depth[i];
		did[i] = i;
	}
	for (int i = 0; i < B; i++)
	{
		cin >> snow[i] >> dist[i];
		bid[i] = i;
	}

	sort(did, did + N, dcmp);
	sort(bid, bid + B, s_bcmp);

	for (int i = 0; i < N; i++)
		nxt[i] = i + 1, pre[i] = i - 1;

	int j = N - 1;
	int maxStep = 1;

	for (int i = B - 1; i >= 0; i--)
	{
		int boot = bid[i];
		while (j >= 0 && depth[did[j]] > snow[boot])
		{
			int cur = did[j];
			nxt[pre[cur]] = nxt[cur];
			pre[nxt[cur]] = pre[cur];
			maxStep = max(maxStep, nxt[cur] - pre[cur]);
			j--;
		}
		ans[boot] = (maxStep <= dist[boot]);
	}

	for (int i = 0; i < B; i++)
		cout << ans[i] << endl;

}
