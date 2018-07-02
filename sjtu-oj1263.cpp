#include <stdio.h>
using namespace std;


int map[55][55];
int dp[55][55][55];

int max(int a, int b) { return a>b ? a : b; }

int main()
{

	int n, m; 
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= i + j; k++){
					dp[i][j][k] = max(max(dp[i - 1][j][k - 1], dp[i - 1][j][k]),max(dp[i][j - 1][k - 1], dp[i][j - 1][k])) + map[i][j] + map[k][i + j - k];
					if (i == k) dp[i][j][k] -= map[i][j];
				}

	printf("%d\n", dp[n][m][n]);
	return 0;
}