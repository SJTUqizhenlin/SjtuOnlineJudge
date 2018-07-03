//see also: "http://codeforces.com/blog/entry/4849"
//probelm: 204D - Little Elephant and Retro Strings

#include <stdio.h>
using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;
typedef unsigned long long ULL;
char S[MAXN];
ULL b[MAXN], c[MAXN], w[MAXN];

//S is the string
//b[i] means numof(all ways s.t.:no k_B_block, until index i)
//c[i] means numof(all ways s.t.:fisrt k_B_block occur on index i)
//w[i] firstly means numof(all ways s.t.:no k_W_block, down_until i)
//w[i] then means numof(all ways s.t.:has k_W_block, down_until i)
//ans is sum of (c[i] * w[i])

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	S[0] = '0'; scanf("%s", S + 1);
	b[0] = 1;
	ULL bad;
	int con_b = 0;
	for (int i = 1; i <= n; i++)
	{
		b[i] = (S[i] == 'X' ? (2 * b[i - 1]) % MOD : b[i - 1]);
		if (S[i] == 'X' || S[i] == 'B')
			con_b++;
		else
		{
			con_b = 0;
			continue;
		}
		if (con_b >= k && S[i - k] != 'B')
		{
			bad = c[i] = (i > k ? b[i - k - 1] : 1);
			b[i] = (b[i] - bad + MOD) % MOD;
		}
		else
			c[i] = 0;
	}
	w[n + 2] = w[n + 1] = 1;
	S[n + 1] = '0';
	int con_w = 0;
	for (int i = n; i >= 1; i--)
	{
		w[i] = (S[i] == 'X' ? (2 * w[i + 1]) % MOD : w[i + 1]);
		if (S[i] == 'W' || S[i] == 'X')
			con_w++;
		else
		{
			con_w = 0;
			continue;
		}
		if (con_w >= k && S[i + k] != 'W')
			w[i] = (w[i] - w[i + k + 1] + MOD) % MOD;
	}
	ULL total = 1;
	for (int i = n; i >= 1; i--)
	{
		total = (S[i] == 'X' ? (2 * total) % MOD : total);
		w[i] = (total - w[i] + MOD) % MOD;
	}
	ULL ans = 0;
	for (int i = 1; i < n; i++)
		ans = (ans + c[i] * w[i + 1]) % MOD;
	printf("%I64u\n", ans);
	return 0;
}