#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp = 0;
	int max = 0;
	int *dp = new int[3];
	int *dppre = new int[3];
	int *ele = new int[3];
	cin >> ele[1];
	cin >> ele[2];
	dp[2] = ele[1] + ele[2];
	dppre[2] = 1;
	max = dp[2];
	int cur = 2;
	for (int i = 3; i <= n; i++)
	{
		cin >> tmp;
		dp[3 - cur] = (dp[cur] > 0 ? dp[cur] : 0) + tmp;
		dppre[3 - cur] = (dp[cur] > 0 ? dppre[cur] : i);
		if (dppre[3 - cur] < i && dp[3 - cur] > max) max = dp[3 - cur];
		cur = 3 - cur;
	}
	if (max > 0) cout << max;
	else cout << "Game Over";
	return 0;
}