#include <iostream>
using namespace std;

const long long MOD = 1000000007;
long long C[1001][1001];
long long res[1001];

void init_C(int n)
{
	C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= MOD;
		}
	}
	return;
}

int left_part(int m)
{
	int x = 1;
	while ((x << 1) + 1 <= m) x = (x << 1) + 1;
	if (m - x <= x / 2 + 1) return (x / 2 + m - x);
	else return x;
}

int main()
{
	int n; cin >> n;
	init_C(n);
	res[0] = res[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int lp = left_part(i);
		int rp = i - 1 - lp;
		res[i] = C[i - 1][lp];
		res[i] = (res[i] * res[lp]) % MOD;
		res[i] = (res[i] * res[rp]) % MOD;
	}
	if (n > 1) cout << (res[n] * 2) % MOD << endl;
	else cout << "1" << endl;
	return 0;
}