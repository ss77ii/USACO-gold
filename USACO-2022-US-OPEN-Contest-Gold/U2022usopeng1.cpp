#include <bits/stdc++.h>
using namespace std;

int N, ans;
struct item {
    int q, t, x, n;
} p[200001];

map<int, int> mp;

bool cmp(const item &a, const item &b) {
	if (a.x - a.t != b.x - b.t) {
        return a.x - a.t < b.x - b.t;
	}
    return a.q > b.q;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i].q >> p[i].t >> p[i].x >> p[i].n;
	}
    sort(p + 1, p + N + 1, cmp);

    for (int i = 1; i <= N; i++) {
        if (p[i].q == 2)
            mp[p[i].x + p[i].t] += p[i].n;
        else {
            int n = p[i].n;
            while (n) {
                map<int, int>::iterator it = mp.lower_bound(p[i].x + p[i].t);
                if (it == mp.end()) break;
                int u = min(n, it->second);
                if (u == it->second)
                    mp.erase(it);
                else
                    it->second -= u;
                n -= u;
                ans += u;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
