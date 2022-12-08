#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n; int q;
ll bitmask[(1 << 18) + 1][18];
ll g[1 << 18];
int E[18];

int main()
{
    cin >> n;
    
    int a[18];
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++) { cin >> a[j]; a[j]--;}
		
		int L = n;
		while(a[L - 1] != i) L--;
		
		for (int j = 0; j < L; j++) {E[i] |= 1 << a[j]; cout << E[i];}
		cout << endl;
	}
	
    g[0] = 1;
    for (int max = 0; max < n; max++){
    	for (int i = 0; i < (1 << max); i++)
    		for (int j = 0; j <= max; j++)
    		{
    			bitmask[i][j] = ((E[j] >> max) & 1) ? g[i] : 0;
    			for (int k = 0; k < max; k++)
    				if ((E[j] >> k & 1) && (i >> k & 1))
    					bitmask[i][j] += bitmask[i - (1 << k)][k];
			}
		for (int i = 1 << max; i < 2 << max; i++) g[i] = bitmask[i - (1 << max)][max];
	}
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		char a[19];
		cin >> a;
		
		int mask = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == 'H') mask |= 1 << i;

		cout << g[mask] * g[(1 << n) - 1 - mask] << endl;
	}

    return 0;
}
