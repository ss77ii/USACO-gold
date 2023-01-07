#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	bool ok[51][51];
	int cows[50001];
	for (int i = 1; i <= n; i++)
	{
		cin >> cows[i];
	}
	char c;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			cin >> c;
			ok[i][j] = (c == '1');
		}
		//remember the cows that can transmit to cow N
		ok[i][0] = ok[i][cows[n]];
	}
	//set cow N to a fake breed 0
	cows[n] = 0;
	vector<int> dis[51];
	for (int i = 0; i <= k; i++)
	{
		dis[i].resize(n + 1);
		for (int j = 0; j <= n; j++)
		{
			dis[i][j] = -1;
		}
	}
	deque<pair<int, int> > q; //sender's breed, location
	q.push_back({cows[1], 1});
	dis[cows[1]][1] = 0;
	
    while (!q.empty())
    {
        pair<int, int> msg = q.front();
        q.pop_front();

        // move left
        if (msg.second - 1 >= 1 && dis[msg.first][msg.second - 1] == -1)
        {
            dis[msg.first][msg.second - 1] = dis[msg.first][msg.second] + 1;
            q.push_back({msg.first, msg.second - 1});
        }
        // move right
        if (msg.second + 1 <= n && dis[msg.first][msg.second + 1] == -1)
        {
            dis[msg.first][msg.second + 1] = dis[msg.first][msg.second] + 1;
            q.push_back({msg.first, msg.second + 1});
        }
        // transmit to current cow
        if (ok[msg.first][cows[msg.second]] && dis[cows[msg.second]][msg.second] == -1)
        {
            dis[cows[msg.second]][msg.second] = dis[msg.first][msg.second];
            q.push_front({cows[msg.second], msg.second});
        }
    }

    cout << dis[cows[n]][n] << endl;

	return 0;
}