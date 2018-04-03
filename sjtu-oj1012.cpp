#include <iostream>

using namespace std;

int main()
{
	long long S, T;
	cin >> S >> T;
	long long *dp = new long long[T - S + 1];
	long long *dptimes = new long long[T - S + 1];
	for (int i = 0; i < T - S + 1; i++) { dp[i] = 1; dptimes[i] = 1; }
	long long tmp;
	long long max = 1;
	for (int cur = 0; cur < T - S + 1; cur++)
	{
		for (int b = 101; b <= 200; b++)
		{
			if (((S + cur) * b) % 100 == 0 && (((S + cur) * b) / 100) <= T)
			{
				tmp = ((S + cur) * b) / 100;
				if (dp[tmp - S] <= dp[cur])
				{
					dp[tmp - S] = dp[cur] + 1;
					dptimes[tmp - S] = dptimes[cur];
				}
				else
					if (dp[tmp - S] == dp[cur] + 1)
					{
						dptimes[tmp - S] += dptimes[cur];
					}
				if ((dp[tmp - S]) > max) max = dp[tmp - S];
			}
			else {}
		}
	}
	long long res = 0;
	for (int i = 0; i < T - S + 1; i++)
		if (dp[i] == max) res += dptimes[i];
	cout << max << endl;
	cout << res;
	return 0;
}