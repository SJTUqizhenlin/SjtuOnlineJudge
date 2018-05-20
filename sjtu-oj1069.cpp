#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[2][100001];

int main()
{
	int aarr[100];
	int carr[100];
	int n, m;
	while (true)
	{
		scanf("%d%d", &n, &m);
		if (n == 0) return 0;
		int cur = 0;
		dp[cur][0] = 1;
		for (int i = 0; i < n; i++)
			scanf("%d", &aarr[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &carr[i]);
		for (int i = 0; i < n; i++)
		{
			cur = 1 - cur;
			for (int j = 0; j <= m; j++)
			{
				if (dp[1 - cur][j] > 0) dp[cur][j] = carr[i] + 1;
				else
				{
					if (j < aarr[i] || dp[cur][j - aarr[i]] == 0)
						dp[cur][j] = 0;
					else
						dp[cur][j] = dp[cur][j - aarr[i]] - 1;
				}
			}
		}
		int count = 0;
		for (int j = 1; j <= m; j++)
		{
			if (dp[cur][j] > 0) count++;
			dp[0][j] = 0;
			dp[1][j] = 0;
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		cout << count << endl;
	}
	return 0;
}