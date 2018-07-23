#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int *arra = new int[n + 1];
	int *arrb = new int[n + 1];
	int *id = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arra[i]);
		id[arra[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arrb[i]);
		arra[id[arrb[i]]] = i;
	}
	int *dp = new int[n + 5];
	for (int i = 0; i < n + 5; i++) dp[i] = 0;
	int pos;
	int reslen = 0;
	for (int i = 1; i <= n; i++)
	{
		pos = upper_bound(dp + 1, dp + 1 + reslen, arra[i]) - dp;
		if (pos > reslen) reslen = pos;
		dp[pos] = arra[i];
	}
	printf("%d\n", reslen);
	return 0;
}