#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 15005;

struct edge { int l, r; long long val; } g[maxn];

bool operator<(const edge &e1, const edge &e2)
{
	return e1.val < e2.val;
}

int Par[maxn];
long long Size[maxn];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		Par[i] = i;
		Size[i] = 1;
	}
}

int findpar(int x)
{
	if (Par[x] == x) return x;
	Par[x] = findpar(Par[x]);
	return Par[x];
}

void unite(int x, int y)
{
	int rx = findpar(x);
	int ry = findpar(y);
	Size[ry] += Size[rx];
	Par[rx] = ry;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		init(n);
		for (int i = 1; i < n; i++) scanf("%d%d%lld", &g[i].l, &g[i].r, &g[i].val);
		sort(g + 1, g + n);
		long long res = 0;
		for (int i = 1; i < n; i++)
		{
			int a = findpar(g[i].l), b = findpar(g[i].r);
			res += Size[a] * Size[b] * (g[i].val + 1);
			res -= 1;
			unite(g[i].l, g[i].r);
		}
		printf("%lld\n", res);
	}
	return 0;
}