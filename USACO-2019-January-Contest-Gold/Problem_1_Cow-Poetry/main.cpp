#include "bits/stdc++.h"
using namespace std;

#define ll long long

ll n, m, k;
ll temp;

struct word
{
    ll s, c;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    vector<word> words(n + 1);
    vector<ll> rhyme(m + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> words[i].s >> words[i].c;
    }

    for (ll i = 1; i <= m; i++)
    {
        cin >> temp;
        rhyme[(temp - 'A')]++;
    }


}