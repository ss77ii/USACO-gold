#include <bits/stdc++.h>

#define MAXN 20
#define f first
#define s second

using namespace std;
 
int main()
{
	string s; cin >> s;
	map<char,int> m; for(char c: s) m[c] = 0;

	int cnt = 0; for (auto& t: m) t.s = cnt++;

	int N = m.size();
    assert(N <= 20);
	vector<vector<int>> oc(N,vector<int>(N));
	for (int i = 0; i+1 < s.size(); ++i) 
		++oc[m[s[i]]][m[s[i+1]]];
	
	for (auto i : oc)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

	vector <int> dp(1 << N);

	dp[0] = 1;
	for (int mask = 1; mask < (1 << N); ++mask)
		dp[mask] = s.length();
	
	for (int mask = 1; mask < (1 << N); ++mask)
	{
		for (int j = 0; j < N; j++)
		{
			if ((mask & (1 << j)) != 0)
			{
				int sum = dp[mask ^ (1 << j)];
				for (int k = 0; k < N; ++k) if ((mask & (1 << k)) != 0) sum += oc[j][k];
                    dp[mask] = min(dp[mask], sum);
			}
		}
	}

	cout << dp[(1 << N) - 1] << endl;

	return 0;
}