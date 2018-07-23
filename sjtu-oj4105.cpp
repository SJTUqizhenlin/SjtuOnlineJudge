#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
int a[MAXN];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int bi, pos;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &bi);
		pos = lower_bound(a, a + n, bi) - a;
		if (a[pos] == bi) { printf("0\n"); continue; }
		if (pos == 0) printf("%d\n", a[pos] - bi);
		else 
			if (pos == n) printf("%d\n", bi - a[n - 1]);
			else
			{
				if (a[pos] - bi < bi - a[pos - 1])
					printf("%d\n", a[pos] - bi);
				else
					printf("%d\n", bi - a[pos - 1]);
			}
	}
	return 0;
}