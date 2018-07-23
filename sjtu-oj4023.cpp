#include <iostream>
#define ls(n) (n << 1)
#define rs(n) ((n << 1) | 1)
using namespace std;

const int MAXN = 100;

struct bread {
	int val, id;
	bread(int vval, int iid)
	{
		val = vval;
		id = iid;
	}
};

bread *arr[MAXN + 5];

void Heap_Exchange(int a, int b)
{
	bread *tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp; return;
}

void Heap_Down(int i, int n)
{
	int maxson;
	while (ls(i) <= n)
	{
		maxson = ls(i);
		if (ls(i) < n && arr[rs(i)]->val > arr[ls(i)]->val)
			maxson = rs(i);
		if (arr[maxson]->val > arr[i]->val)
		{
			Heap_Exchange(i, maxson);
			i = maxson;
		}
		else break;
	}
	return;
}

void Heap_Pop(int hsize)
{
	Heap_Exchange(1, hsize);
	Heap_Down(1, hsize - 1);
	return;
}

void HeapSort(bread **arr, int n)
{
	for (int i = n; i >= 1; i--)
		Heap_Down(i, n);
	for (int i = 0; i < n; i++)
		Heap_Pop(n - i);
	return;
}

int Rank[MAXN + 5];
int Pair[MAXN + 5];

struct node
{
	int l, r, len;
	int val, tag;
	node() {
		val = tag = 0;
		l = r = len = 0;
	}
};

node segtr[MAXN * 4 + 20];

void segtr_push_up(int root)
{
	segtr[root].val = segtr[ls(root)].val + segtr[rs(root)].val;
	return;
}

void segtr_build(int root, int l, int r)
{
	segtr[root].l = l; segtr[root].r = r;
	segtr[root].len = r - l + 1;
	if (r == l) { segtr[root].val = 0; return; }
	int mid = (l + r) >> 1;
	segtr_build(ls(root), l, mid);
	segtr_build(rs(root), mid + 1, r);
	segtr_push_up(root); return;
}

void segtr_fill_tag(int root, int k)
{
	segtr[root].tag += k;
	segtr[root].val += k * segtr[root].len;
	return;
}

void segtr_push_down(int root)
{
	segtr_fill_tag(ls(root), segtr[root].tag);
	segtr_fill_tag(rs(root), segtr[root].tag);
	segtr[root].tag = 0; return;
}

void segtr_update(int x, int y, int root, int k)
{
	if (x <= segtr[root].l && y >= segtr[root].r) {
		segtr_fill_tag(root, k); return;
	}
	segtr_push_down(root);
	if (x <= segtr[ls(root)].r)
		segtr_update(x, y, ls(root), k);
	if (y >= segtr[rs(root)].l)
		segtr_update(x, y, rs(root), k);
	segtr_push_up(root); return;
}

int segtr_query(int x, int y, int root)
{
	if (x <= segtr[root].l && y >= segtr[root].r)
		return segtr[root].val;
	int res = 0;
	segtr_push_down(root);
	if (x <= segtr[ls(root)].r)
		res += segtr_query(x, y, ls(root));
	if (y >= segtr[rs(root)].l)
		res += segtr_query(x, y, rs(root));
	return res;
}

int main()
{
	int n, tmp; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		arr[i] = new bread(tmp, i);
	}
	HeapSort(arr, n);
	int tmpRank = 0; 
	Rank[arr[1]->id] = (++tmpRank);
	for (int i = 2; i <= n; i++)
	{
		if (arr[i]->val > arr[i - 1]->val)
			++tmpRank;
		Rank[arr[i]->id] = tmpRank;
	}
	segtr_build(1, 1, tmpRank);
	for (int i = 1; i <= n; i++)
	{
		segtr_update(Rank[i], Rank[i], 1, 1);
		if (Rank[i] > 1) Pair[i] = segtr_query(1, Rank[i] - 1, 1);
	}
	cout << Pair[1];
	for (int i = 2; i <= n; i++)
		cout << " " << Pair[i];
	return 0;
}