#include <stdio.h>
using namespace std;

int arra[100005];

int FindGreater(int d, int l, int r)
{
	if (l >= r - 1) return l;
	int mid = (l + r) / 2;
	if (arra[mid - 1] <= d) return FindGreater(d, mid, r);
	else return FindGreater(d, l, mid);
}

int main()
{
	int n, k; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arra[i]);
	scanf("%d", &k); int b, c;
	int d, res;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &b, &c);
		d = (b * b) / (4 * c);
		if (arra[n - 1] <= d)
			res = n;
		else 
			res = FindGreater(d, 0, n);
		printf("%d\n", res);
	}
	return 0;
}