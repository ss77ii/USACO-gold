//  Problem 1. Why Did the Cow Cross the Road

#include <bits/stdc++.h>
using namespace std;

void setIO(const string& s)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int dr[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dc[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

int main() {
	setIO("visitfj");
	int N, T;
	cin >> N >> T;

	vector<vector<int> > A(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	vector<vector<int> > D(N, vector<int>(N, 0x7FFFFFFF));
	D[0][0] = 0;

	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 0));

	int result = 0x7FFFFFFF;
	while (!q.empty()) {
		int d = -q.top().first;
		int r = q.top().second / N;
		int c = q.top().second % N;
		q.pop();
		if (d != D[r][c]) {
			continue;
		}

		int dist = abs(N - 1 - r) + abs(N - 1 - c);
		if (dist <= 2) {
			result = min(result, d + dist * T);
		}

		for (int i = 0; i < sizeof(dr) / sizeof(int); i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N ||
			    D[nr][nc] < d + A[nr][nc] + 3 * T) {
				continue;
			}
			D[nr][nc] = d + A[nr][nc] + 3 * T;
			q.push(make_pair(-D[nr][nc], nr * N + nc));
		}
	}
	cout << result << endl;

	return 0;
}