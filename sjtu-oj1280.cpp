#include <iostream>  
using namespace std;

long long dp[2005][1005];
int val[2005];
const long long MOD = 100000000;

int main()
{
	int N, F;
	cin >> N >> F;
	int isF = 0, notF = 0;
	int tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		if (tmp % F == 0) isF++;
		else val[++notF] = (tmp % F);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= notF; i++) {
		for (int j = 0; j < F; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j + (j >= val[i] ? 0 : F) - val[i]];
			dp[i][j] %= MOD;
		}
	}
	long long res = dp[notF][0];
	while (isF--) res = (res << 1) % MOD;
	cout << ((res + MOD - 1) % MOD) << endl;
	return 0;
}