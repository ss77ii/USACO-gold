#include <bits/stdc++.h>
using namespace std;

const int N =  2e5 + 1;
int dp[N];
set<string> s;

int main()
{
    // freopen("name.in","r",stdin);
    // freopen("name.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tp;
    int maxLen = 0;
    while (cin >> tp)
    {
        if (tp == ".") break;
        s.insert(tp);
        maxLen = max(maxLen, int(tp.size()));
    }

    int ans = 0;
    dp[0] = 1;
    string n = " ";

    while (cin >> tp)
    {
        n = n + tp;
    }

    for (int i = 1; i < n.size(); i++)
    {
		for (int j = min(maxLen, i); j >= 1; j--)
        {
            string t = n.substr(i - j + 1, j);
            if (s.count(t) >= 1 && dp[i - j] == 1)
            {
                ans = i;
                dp[i] = 1;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
