#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define squ(a) ((a) * (a))
using namespace std;
typedef long long LL;

int n, m, k;
int arr1[1005][1005], arr2[1005][1005];

int binFind(int a, int l, int r)
{
	if (r - l <= 1) return r;
	int mid = (l + r) / 2;
	if (squ(mid) > a) return binFind(a, l, mid);
	else return binFind(a, mid, r);
}

int findRoot(int a)
{
	if (a <= 1) return (a + 1);
	int res = binFind(a, 0, a);
	return res;
}

void paintOn(int x0, int y0, int r0)
{
	int u = x0 - r0, d = x0 + r0;
	u = max(u, 1);
	d = min(d, n);
	int tmp, l, r;
	for (int i = u; i <= d; i++)
	{
		tmp = findRoot(squ(r0) - squ(i - x0));
		l = y0 - tmp + 1; l = max(1, l);
		r = y0 + tmp - 1; r = min(m, r);
		arr1[i][l]++; arr2[i][r]++;
	}
	return;
}

int countOn(int i)
{
	int count_1 = 0, beg = 0, res = 0;
	int j = 1;
	while (j <= n && arr1[i][j] == 0) ++j;
	if (j > n) return 0;
	for (j; j <= n; j++)
	{
		count_1 += arr1[i][j];
		if (beg == 0 && arr1[i][j] > 0) beg = j;
		count_1 -= arr2[i][j];
		if (arr2[i][j] > 0 && count_1 == 0)
		{
			res += (j - beg + 1);
			beg = 0;
		}
	}
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int x0, y0, r0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &x0, &y0, &r0);
		paintOn(x0, y0, r0);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += countOn(i);
	printf("%d\n", res);
	return 0;
}