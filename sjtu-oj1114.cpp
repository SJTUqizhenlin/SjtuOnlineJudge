#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 300005;

struct node
{
	int l;
	int r;
	int sum;
	node()
		:l(0), r(0), sum(0) {}
};

node tree[maxn * 30];
int Count;

void Insert(int pos, int &n, int l, int r)
{
	tree[Count++] = tree[n];
	n = Count - 1;
	tree[n].sum++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) Insert(pos, tree[n].l, l, mid);
	else Insert(pos, tree[n].r, mid + 1, r);
}

int Query(int ni, int nj, int k, int l, int r)
{
	if (l == r) return l;
	int tmp = tree[tree[nj].l].sum - tree[tree[ni].l].sum;
	int mid = (r + l) >> 1;
	if (k <= tmp) return Query(tree[ni].l, tree[nj].l, k, l, mid);
	else return Query(tree[ni].r, tree[nj].r, k - tmp, mid + 1, r);
}

struct Pair
{
	int val;
	int id;
	Pair()
		:val(0), id(0) {}
	bool operator<(const Pair &rhs) const
	{
		return val < rhs.val;
	}
};

Pair arr[maxn];
int Rank[maxn];
int Root[maxn];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i].val);
		arr[i].id = i;
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) Rank[arr[i].id] = i;
	Count = 1;
	for (int i = 1; i <= n; i++)
	{
		Root[i] = Root[i - 1];
		Insert(Rank[i], Root[i], 1, n);
	}
	int m;
	cin >> m;
	int i, j, k;
	int ans;
	while (m--)
	{
		scanf("%d%d%d", &i, &j, &k);
		ans = Query(Root[i - 1], Root[j], k, 1, n);
		printf("%d\n", arr[ans].val);
	}
	return 0;
}
