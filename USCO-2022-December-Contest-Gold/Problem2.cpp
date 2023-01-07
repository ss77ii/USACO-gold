#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

typedef long long ll;
#define ff first
#define ss second
int N, Q;
ll h[5100];
set<int> rig[5100]; // monotonic sets

bool comp(int ind, int i1, int i2) {
    // does index i2 to ind have a greater slope than index i1 to ind
    int d1 = abs(ind - i1), d2 = abs(ind - i2);
    ll h1 = h[i1] - h[ind], h2 = h[i2] - h[ind];
    return h2 * d1 >= h1 * d2;
}

int main() {
    fastIO();
    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> h[i]; }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (rig[i].empty()) {
                rig[i].insert(j);
            } else {
                if (comp(i, *rig[i].rbegin(), j)) { rig[i].insert(j); }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) ans += (int)rig[i].size();
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int x, y;
        cin >> x >> y; // update mountain x by incrementing it by height y
        h[x] += y;
        // update the sets to the left of x
        for (int j = 1; j <= x - 1; j++) {
            auto it = rig[j].lower_bound(x);
            bool add = false;
            if ((*it) == x) {
                add = true;
                it++;
            } else {
                --it;
                if (comp(j, (*it), x)) {
                    rig[j].insert(x);
                    ans++;
                    add = true;
                    it++;
                    it++;
                }
            }
            if (add) {
                while (it != rig[j].end() && !comp(j, x, (*it))) {
                    it = rig[j].erase(it);
                    ans--;
                }
            }
        }
        // update the set for x
        ans -= (int)rig[x].size();
        rig[x].clear();
        for (int j = x + 1; j <= N; j++) {
            if (rig[x].empty()) {
                rig[x].insert(j);
                ans++;
            } else {
                if (comp(x, *rig[x].rbegin(), j)) {
                    rig[x].insert(j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}