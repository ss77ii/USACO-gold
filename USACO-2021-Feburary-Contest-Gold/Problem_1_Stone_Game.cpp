#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> A(N);
	int mx = 0;
	
	for (int& t: A)
	{
		cin >> t;
		mx = max(mx,t);
	}

	vector<int> cum(mx + 1);
	for (int t: A) ++cum[t];
	for (int i = 1; i <= mx; ++i) cum[i] += cum[i-1];
	auto getCum = [&](int ind)
	{ // number of elements of A <= ind
		if (ind > mx) return cum.back();
		return cum[ind];
	};

	long long ans = 0;
	for (int x = 1; x <= mx; ++x)
	{
		vector <int> cnt{getCum(x-1)};
		vector <int> odd;
		for (int t = 1; x * t <= mx; ++t)
			cnt.push_back(getCum(x*(t+1)-1) - getCum((x*t)-1));

		for (int t = 1; t < cnt.size(); ++t)
			if (cnt[t] % 2 == 1)
				odd.push_back(t);
		if (odd.size() == 1 && odd[0] == 1)
			ans += cnt[odd[0]];
		else if (odd.size() == 2 && odd[0]+1==odd[1])
			ans += cnt[odd[1]];
	}
	cout << ans << endl;
}

// 9 8 8 4 4 4 2 2 2

// 1 + 3 + 3 + 3 + 3 + 3
