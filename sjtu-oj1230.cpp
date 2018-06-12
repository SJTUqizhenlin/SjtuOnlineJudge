#include <stdio.h>
using namespace std;

int arr[2005];
int presum[2005];
int dp[2005][2005];
int cost[2005][2005];
int n, m;

void init_arr()
{
	scanf("%d%d", &n, &m);
	presum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &(arr[i]));
		presum[i] = presum[i - 1] + arr[i];
	}
	return;
}

void init_cost()
{
	int tmp, mid;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			tmp = 0; mid = (i + j) / 2;
			tmp += (arr[mid] * (mid - i) - (presum[mid - 1] - presum[i - 1]));
			tmp += ((presum[j] - presum[mid]) - arr[mid] * (j - mid));
			cost[i][j] = tmp;
		}
	return;
}

void filldp()
{
	for (int i = 1; i <= n; i++) dp[1][i] = cost[1][i];
	int minres;
	for (int i = 2; i <= m; i++)
		for (int j = i + 1; j <= n - m + i; j++)
		{
			minres = 1000000001;
			for (int k = j - 1; k >= i - 1 && cost[k + 1][j] < minres; k--)
				if (dp[i - 1][k] + cost[k + 1][j] < minres)
					minres = dp[i - 1][k] + cost[k + 1][j];
			dp[i][j] = minres;
		}
	return;
}

int main()
{
	init_arr();
	init_cost();
	filldp();
	printf("%d\n", dp[m][n]);
	return 0;
}