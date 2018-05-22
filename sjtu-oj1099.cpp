#include <iostream>

using namespace std;

long long chart[101][101];
long long dp[101][101];
int numofc[101];

void init_chart(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			for (int k = 1; k <= j; k++)
				chart[i][j] += chart[i - j][k];
		chart[i][i] = 1;
	}
	return;
}

int main()
{
	int N, C, tmp, maxnumofc = 0;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		numofc[tmp] += 1;
		if (numofc[tmp] > maxnumofc) maxnumofc = numofc[tmp];
	}
	init_chart(maxnumofc);
	int maxboxnum = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= C; i++)
	{
		maxboxnum += numofc[i];
		dp[i][i] = 1;
		for (int j = i + 1; j <= maxboxnum; j++)
		{
			for (int k = i - 1; k < j; k++)
				dp[i][j] += dp[i - 1][k] * chart[numofc[i]][j - k];
		}
	}
	long long res = 0;
	for (int i = C; i <= N; i++)
		res += dp[C][i];
	cout << res << endl;
	return 0;
}