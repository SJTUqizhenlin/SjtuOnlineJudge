#include <stdio.h>
using namespace std;

int T, M;
int costs[110], values[110];
int dp[110][1010];

int main()
{
	scanf("%d%d", &T, &M);
	for (int i = 1; i <= M; i++) scanf("%d%d", &costs[i], &values[i]);
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (costs[i] <= j)
				if (dp[i - 1][j - costs[i]] + values[i] > dp[i][j])
					dp[i][j] = dp[i - 1][j - costs[i]] + values[i];
		}
	}
	printf("%d\n", dp[M][T]);
	return 0;
}