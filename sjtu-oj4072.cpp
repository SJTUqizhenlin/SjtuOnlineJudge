#include <stdio.h>
using namespace std;

int n, m, k;
const int maxn = 100005;
const int maxl = 1000000005;
int pathu[maxn];
int pathv[maxn];
int lengl[maxn];
int flagp[maxn];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &pathu[i], &pathv[i], &lengl[i]);
	int tmpint;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &tmpint);
		flagp[tmpint] = 1;
	}
	int res = maxl;
	for (int i = 0; i < m; i++)
		if (flagp[pathu[i]] != flagp[pathv[i]])
			if (lengl[i] < res) res = lengl[i];
	if (res < maxl) printf("%d\n", res);
	else printf("-1\n");
	return 0;
}