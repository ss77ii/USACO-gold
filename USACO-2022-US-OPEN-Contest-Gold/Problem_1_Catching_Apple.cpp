#include <bits/stdc++.h>
using namespace std;

/*
cow: event i
apple: event j

ti <= tj  && abs(xi-xj) <= tj-ti


xi - xj <= tj - ti -> xi + ti <= xj + tj 
xj - xi <= tj - ti -> xj - tj <= xi - ti

P(xi-ti, xi+ti)
*/

int n;

struct item
{
    int q, t, x, n;
} p[200001];

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].q >> p[i].t >> p[i].x >> p[i].n;
	}
	
	return 0;
}

