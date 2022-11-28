#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, f[100000];
pair<int, int> cow[100000];
vector<pair<int, int> > edges[201];

ll ans;
inline ll sqr(ll x) { return x * x; }

inline ll dis(int u, int v) {
    return sqr(cow[u].first - cow[v].first) +
           sqr(cow[u].second - cow[v].second);
}

int find(int v) {
	if(f[v] == v) {
		return v;
	}

	f[v] = find(f[v]);
	return f[v];
}

bool merge(int u, int v) {
	int fu = find(u);
	int fv = find(v);
	if(fu != fv) {
		f[fv] = fu;
        return true;
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cow[i].first >> cow[i].second;
    }
    
    sort(cow, cow + N);

    for (int i = 0; i < N; i++) f[i] = i;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N && j <= i + 150; j++) {
            long long d = dis(i, j);
            if (d <= 200) edges[d].push_back({i, j});
        }

    for (int i = 0; i <= 200; i++)
        for (pair<int, int> e : edges[i]) {
            if (merge(e.first, e.second)) ans += i;
        }

    for (int i = 0, j; i < N; i = j) {
        j = i + 1;
        while (j < N && find(i) == find(j)) j++;
        if (i) {
            long long T = LLONG_MAX;
            for (int x = i - 1; x >= 0 && x >= i - 50; x--)
                for (int y = i; y < j && y <= i + 50; y++) {
                    T = min(T, dis(x, y));
                }
            ans += T;
        }
    }
    cout << ans << endl;
    return 0;
}
