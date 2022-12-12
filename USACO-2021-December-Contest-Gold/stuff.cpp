#include <bits/stdc++.h>
using namespace std;

set<int> x;
int main()
{
    x.insert(10);
    x.insert(1);
    x.insert(2);
    x.insert(9);
    x.insert(5);
    x.insert(6);

    cout << *x.lower_bound(8);
    cout << endl << *(--x.end());
    return 0;
}