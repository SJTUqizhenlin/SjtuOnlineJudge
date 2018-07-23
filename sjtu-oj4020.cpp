#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1005];
int dp[1005][1005];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = (arr[i] == i) ? (dp[i - 1][0] + 1) : (dp[i - 1][0]);
		for (int j = 1; j < i; j++)
		{
			if (arr[i] == i - j) dp[i][j] = dp[i - 1][j] + 1;
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	int res = 0;
	for (int j = 0; j <= n; j++) if (dp[n][j] > res) res = dp[n][j];
	printf("%d\n", res);
	return 0;
}