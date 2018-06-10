#include <stdio.h>
#include <algorithm>

using namespace std;

struct numnode
{
	int num;
	int id;
	numnode() :num(0), id(0) {}
	numnode(int n, int i) :num(n), id(i) {}
	bool operator<(const numnode& rhs) const
	{
		return num < rhs.num;
	}
};

int lowbit(int a) { return a & (-a); }

void bit_add(int x, int* bitr, int N)
{
	while (x <= N)
	{
		bitr[x] += 1;
		x += lowbit(x);
	}
	return;
}

long long bit_sum(int x, int* bitr)
{
	long long res = 0;
	while (x > 0)
	{
		res += bitr[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	numnode* arr = new numnode[n + 1];
	numnode* cop = new numnode[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i].num);
		arr[i].id = i;
		cop[i].num = arr[i].num;
		cop[i].id = arr[i].id;
	}
	sort(cop + 1, cop + n + 1);
	int *rnkofid = new int[n + 1];
	for (int i = 1; i <= n; i++) rnkofid[cop[i].id] = i;
	int *dblofid = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		numnode tmp(arr[i].num * 2, 0);
		dblofid[i] = upper_bound(cop + 1, cop + n + 1, tmp) - cop;
	}
	int *bitr = new int[n + 1];
	for (int i = 0; i <= n; i++) bitr[i] = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		bit_add(rnkofid[i], bitr, n);
		res += (i - bit_sum(dblofid[i] - 1, bitr));
	}
	printf("%lld\n", res);
	return 0;
}