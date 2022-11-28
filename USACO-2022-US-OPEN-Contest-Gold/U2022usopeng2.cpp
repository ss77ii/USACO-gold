#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
int T, n;
string a, b;
int f[2005][2005];
int g[2005][2005];

string get() {
    string s, t;
    cin >> s;
    for (char c : s) {
        if (c == '0') {
            t = "0";
        } else if (c != '1') {
            t += c;
        }
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        a = get();
        b = get();
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        f[1][0] = 1;
        g[0][1] = 1;
        for (int i = 0; i <= a.size(); i++) {
            for (int j = 0; j <= b.size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i < a.size()) {
                    f[i + 1][j] = (f[i + 1][j] + f[i][j]) % p;
                    if (j > 0 && b[j - 1] != '+' && a[i] == '+') {
                        f[i + 1][j] = (f[i + 1][j] + g[i][j]) % p;
                    }
                    if (j > 0 && b[j - 1] == '+' && a[i] != '+') {
                        f[i + 1][j] = (f[i + 1][j] + g[i][j]) % p;
                    }
                }
                if (j < b.size()) {
                    g[i][j + 1] = (g[i][j + 1] + g[i][j]) % p;
                    g[i][j + 1] = (g[i][j + 1] + f[i][j]) % p;
                }
            }
        }
        cout << (f[a.size()][b.size()] + g[a.size()][b.size()]) % p << endl;
    }
    return 0;
}
