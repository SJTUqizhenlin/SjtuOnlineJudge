#include <iostream>

using namespace std;

const int m = 19301;
int dp[4000];

int main()
{
	int N;
	cin >> N;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] += dp[i - 1];
		dp[i] %= m;
		for (int j = 0; j <= i - 2; j++)
		{
			dp[i] += dp[j] * dp[i - j - 2];
			dp[i] %= m;
		}
	}
	cout << dp[N] << endl;
	return 0;
}