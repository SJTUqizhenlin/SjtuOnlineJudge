#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int gph[101][101];

int main()
{
	int n;
	cin >> n;
	int a, b, d;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b >> d;
		gph[a][b] = d;
		gph[b][a] = d;
	}
	int m;
	cin >> m;
	int distance[101];
	bool flag[101];
	queue<int> q;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		memset(distance, 0, sizeof(int) * (n + 1));
		memset(flag, 0, sizeof(bool) * (n + 1));
		flag[a] = 1;
		q.push(a);
		int tmp;
		while (!q.empty())
		{
			tmp = q.front();
			for (int j = 1; j <= n; j++)
				if (gph[tmp][j] && !flag[j])
				{
					q.push(j);
					distance[j] = distance[tmp] + gph[tmp][j];
					flag[j] = 1;
				}
			q.pop();
		}
		cout << distance[b] << endl;
	}
	return 0;
}