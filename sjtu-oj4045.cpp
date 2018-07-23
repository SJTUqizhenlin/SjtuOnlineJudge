#include <stdio.h>
using namespace std;

int arr[10005];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	int  l, r, x, Count_less;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &l, &r, &x);
		if (x < l || x > r) { printf("Yes\n"); continue; }
		Count_less = 0;
		for (int j = l; j <= r; j++)
			if (arr[j] < arr[x]) ++Count_less;
		if (Count_less == x - l) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}