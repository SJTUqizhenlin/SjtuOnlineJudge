#include <stdio.h>
#include <algorithm>
using namespace std;

struct edge
{
	int val, n1, n2;
	edge() :val(0), n1(0), n2(0) {}
	bool operator<(const edge &rhs) const
	{
		return val < rhs.val;
	}
};

edge arr[5005];
int prt[5005];
int hgt[5005];

int find_prt(int x)
{
	if (prt[x] == x) return x;
	return prt[x] = find_prt(prt[x]);
}

void union_set(int x, int y)
{
	x = find_prt(x); y = find_prt(y);
	if (hgt[x] < hgt[y]) prt[x] = y;
	else
	{
		prt[y] = x;
		if (hgt[x] == hgt[y]) ++hgt[x];
	}
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	if (n <= 2) { printf("%d\n", 0); return 0; }
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		arr[i].val = w;
		arr[i].n1 = u;
		arr[i].n2 = v;
	}
	sort(arr + 1, arr + m + 1);
	int res = 50000;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++) { prt[j] = j; hgt[j] = 1; }
		int Count = 0;
		int upbound = arr[i].val;
		for (int j = i; j <= m; j++)
		{
			if (Count == n - 1)
			{
				if (upbound - arr[i].val < res)
					res = upbound - arr[i].val;
				break;
			}
			int a = arr[j].n1;
			int b = arr[j].n2;
			if (find_prt(a) != find_prt(b))
			{
				union_set(a, b);
				upbound = arr[j].val;
				++Count;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}