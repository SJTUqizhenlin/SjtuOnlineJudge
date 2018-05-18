#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

int main()
{
	int l, n;
	cin >> l >> n;
	int **graph = new int*[l];
	for (int i = 0; i < l; i++)
	{
		graph[i] = new int[l];
		for (int j = 0; j < l; j++)
			scanf("%d", &graph[i][j]);
	}
	int *order = new int[n];
	int tmpo;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmpo);
		order[i] = tmpo - 1;
	}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << order[i] << endl;
	//}
	long long **dp[2];
	for (int i = 0; i < 2; i++)
	{
		dp[i] = new long long*[l];
		for (int j = 0; j < l; j++)
		{
			dp[i][j] = new long long[l];
			for (int k = 0; k < l; k++)
				dp[i][j][k] = INT32_MAX;
		}
	}
	int cur = 0;
	dp[cur][0][1] = dp[cur][1][0] = 0;
	dp[cur][0][2] = dp[cur][2][0] = 0;
	dp[cur][1][2] = dp[cur][2][1] = 0;
	int o = 0;
	while ((o < n) && (order[o] >= 0 && order[o] <= 2)) o++;
	if (o < n)
	{
		dp[cur][0][1] = dp[cur][1][0] = graph[2][order[o]];
		dp[cur][0][2] = dp[cur][2][0] = graph[1][order[o]];
		dp[cur][1][2] = dp[cur][2][1] = graph[0][order[o]];
		o++;


		//cout << endl;
		//for (int x = 0; x < l; x++)
		//{
		//	for (int y = 0; y < l; y++)
		//		cout << dp[cur][x][y] << " ";
		//	cout << endl;
		//}


	}
	long long min;
	for (; o < n; o++)
	{
		cur = 1 - cur;
		for (int x = 0; x < l; x++)
			for (int y = 0; y < l; y++)
				dp[cur][x][y] = INT32_MAX;
		for (int x = 0; x < l; x++)
			for (int y = 0; y < l; y++)
			{
				if ((x == order[o - 1] || y == order[o - 1]) || (x == y)) continue;
				if ((x != order[o] && y != order[o]) && dp[1 - cur][x][y] + graph[order[o - 1]][order[o]] < dp[cur][x][y])
					dp[cur][x][y] = dp[cur][y][x] = dp[1 - cur][x][y] + graph[order[o - 1]][order[o]];
				if ((y != order[o] && order[o - 1] != order[o]) && dp[1 - cur][x][y] + graph[x][order[o]] < dp[cur][order[o - 1]][y])
					dp[cur][order[o - 1]][y] = dp[cur][y][order[o - 1]] = dp[1 - cur][x][y] + graph[x][order[o]];
				if ((x != order[o] && order[o - 1] != order[o]) && dp[1 - cur][x][y] + graph[y][order[o]] < dp[cur][x][order[o - 1]])
					dp[cur][x][order[o - 1]] = dp[cur][order[o - 1]][x] = dp[1 - cur][x][y] + graph[y][order[o]];
			}

		
		//cout << endl;
		//for (int x = 0; x < l; x++)
		//{
		//	for (int y = 0; y < l; y++)
		//		cout << dp[cur][x][y] << " ";
		//	cout << endl;
		//}


	}
	long long ans = INT32_MAX;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			if (ans > dp[cur][i][j])
				ans = dp[cur][i][j];
	cout << ans << endl;
	return 0;
}