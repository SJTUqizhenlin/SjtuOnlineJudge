#include <iostream>

using namespace std;

long long chart[30][15];

int main()
{
	for (int i = 1; i < 30; i += 2)
	{
		chart[i][0] = 1;
		for (int j = 1; j <= (i >> 1); j++)
		{
			chart[i][j] = chart[i][j - 1] * (i - j + 1) / j;
		}
	}
	int T;
	cin >> T;
	int n;
	long long ans;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		ans = 0;
		for (int j = 0; j <= (n >> 1); j++)
			ans += chart[n][j];
		cout << ans << endl;
	}
	return 0;
}