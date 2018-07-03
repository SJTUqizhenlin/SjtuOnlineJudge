#include <stdio.h>
using namespace std;

int parent[1005];
int height[1005];
int N, M;

struct HPint
{
	static const int maxn = 500;
	int len;
	int s[maxn];
	HPint() { len = 0; }
	HPint(int e)
	{
		len = 0;
		while(e)
		{
			s[++len] = e % 10;
			e /= 10;
		}
		if (len == 0)
		{
			len = 1;
			s[1] = 0;
		}
	}
	void print_self()
	{
		for (int i = len; i > 0; i--) printf("%d", s[i]);
		return;
	}
	HPint& operator=(const HPint &rhs)
	{
		len = rhs.len;
		for (int i = 1; i <= len; i++)
			s[i] = rhs.s[i];
		return *this;
	}
	HPint& operator+(const HPint &rhs) const
	{
		HPint *res = new HPint(0);
		int i = 1;
		while (i <= len || i <= rhs.len || (*res).s[i] > 0)
		{
			if (i <= len) (*res).s[i] += s[i];
			if (i <= rhs.len) (*res).s[i] += rhs.s[i];
			(*res).s[i + 1] = (*res).s[i] / 10;
			(*res).s[i] %= 10;
			++i;
		}
		(*res).len = i - 1;
		if ((*res).len == 0) (*res).len = 1;
		return (*res);
	}
};

int find_parent(int x)
{
	if (parent[x] == x) return x;
	parent[x] = find_parent(parent[x]);
	return (parent[x]);
}

void Union(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if (x == y) return;
	if (height[x] < height[y]) parent[x] = y;
	else
	{
		parent[y] = x;
		if (height[x] == height[y]) ++height[x];
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	int x, y;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		height[i] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		Union(x, y);
	}
	int Count = N;
	for (int i = 1; i <= N; i++) if (parent[i] == i) --Count;
	HPint res(1);
	for (int i = 0; i < Count; i++) res = res + res;
	res.print_self();
	printf("\n");
	return 0;
}
