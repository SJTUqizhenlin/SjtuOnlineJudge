#include <stdio.h>
#include <algorithm>

using namespace std;

long long dp[1005];
int p[1005];
int w[1005];
int v[1005];
int n, m;

void zeroone_pack(int cost, int value)
{
	for (int i = m; i >= cost; i--)
		dp[i] = max(dp[i], dp[i - cost] + value);
}

void complete_pack(int cost, int value)
{
	for (int i = cost; i <= m; i++)
		dp[i] = max(dp[i], dp[i - cost] + value);
}

void multi_pack()
{
	for (int i = 1; i <= n; i++)
	{
		if (p[i] * w[i] > m)
			complete_pack(w[i], v[i]);
		else
		{
			int k = 1;
			while (k < p[i])
			{
				zeroone_pack(k * w[i], k * v[i]);
				p[i] -= k;
				k <<= 1;
			}
			zeroone_pack(p[i] * w[i], p[i] * v[i]);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &p[i], &w[i], &v[i]);
	multi_pack();
	long long max = 0;
	for (int i = 0; i <= m; i++)
		if (dp[i] > max) max = dp[i];
	printf("%lld\n", max);
	return 0;
}