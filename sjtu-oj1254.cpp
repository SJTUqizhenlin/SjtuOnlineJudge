#include <iostream>

using namespace std;

int dp[31][31];

int main()
{
	int n, m;
	cin >> n >> m;
	dp[1][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		dp[1][i] = dp[2][i - 1] + dp[n][i - 1];
		dp[n][i] = dp[1][i - 1] + dp[n - 1][i - 1];
		for (int j = 2; j <= n - 1; j++)
			dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
	}
	cout << dp[1][m] << endl;
	return 0;
}