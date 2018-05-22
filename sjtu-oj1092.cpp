#include <iostream>
using namespace std;

int n, m;
long long dp[12][515];

void dfs(int i, int j, int state, int nxt)
{
	if (j == n)
	{
		dp[i + 1][nxt] += dp[i][state];
		return;
	}
	if ((state & (1 << j)) > 0)
		dfs(i, j + 1, state, nxt);
	if ((state & (1 << j)) == 0)
	{
		if ((nxt & (1 << j)) == 0)
			dfs(i, j + 1, state, (nxt | (1 << j)));
		if (j > 0 && ((nxt & (1 << j)) == 0) && ((nxt & (1 << (j - 1))) == 0))
			dfs(i, j + 1, state, ((nxt | (1 << j)) | (1 << (j - 1))));
		if (j + 1 < n && ((nxt & (1 << j)) == 0) && ((nxt & (1 << (j + 1))) == 0))
			dfs(i, j + 1, state, ((nxt | (1 << j)) | (1 << (j + 1))));
	}
	if (j + 1 < n && ((1 << j) & state) == 0 && ((1 << (j + 1)) & state) == 0)
	{
		dfs(i, j + 2, state, nxt);
		if ((nxt & (1 << j)) == 0)
			dfs(i, j + 2, state, (nxt | (1 << j)));
		if ((nxt & (1 << (j + 1))) == 0)
			dfs(i, j + 2, state, (nxt | (1 << (j + 1))));
	}
	return;
}

int main()
{
	cin >> n >> m;
	dp[1][0] = 1;
	for (int i = 1; i <= m; i++)
		for (int state = 0; state < (1 << n); state++)
		{
			if (dp[i][state])
			{
				dfs(i, 0, state, 0);
			}
		}
	cout << dp[m + 1][0] << endl;
	return 0;
}