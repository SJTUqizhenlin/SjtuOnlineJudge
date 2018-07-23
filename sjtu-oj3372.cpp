/*

This is not sjtu oj,
actually luogu oj(www.luogu.org)

*/
#include <stdio.h>
#define ls(p) (p << 1)
#define rs(p) ((p << 1) | 1)
using namespace std;
typedef long long LL;
const int MAXN = 100000;

struct node
{
	int l, r, len;
	LL val, tag;
	node() {
		l = r = len = 0;
		val = tag = 0;
	}
};

int N, M;
LL arr[MAXN + 5];
node segtr[MAXN * 4 + 20];

void push_up(int root) {
	segtr[root].val = segtr[ls(root)].val + segtr[rs(root)].val;
	return;
}

void build(int root, int l, int r)
{
	segtr[root].l = l; segtr[root].r = r;
	segtr[root].len = segtr[root].r - segtr[root].l + 1;
	if (l == r) { segtr[root].val = arr[l]; return; }
	int mid = (l + r) >> 1;
	build(ls(root), l, mid);
	build(rs(root), mid + 1, r);
	push_up(root);
	return;
}

void fill_tag(int root, LL k)
{
	segtr[root].tag += k;
	segtr[root].val += k * segtr[root].len;
	return;
}

void push_down(int root)
{
	fill_tag(ls(root), segtr[root].tag);
	fill_tag(rs(root), segtr[root].tag);
	segtr[root].tag = 0;
	return;
}

void update(int x, int y, int root, LL k)
{
	if (x <= segtr[root].l && y >= segtr[root].r)
	{
		segtr[root].val += k * segtr[root].len;
		segtr[root].tag += k;
		return;
	}
	push_down(root);
	if (x <= segtr[ls(root)].r)
		update(x, y, ls(root), k);
	if (y >= segtr[rs(root)].l)
		update(x, y, rs(root), k);
	push_up(root);
	return;
}

LL query(int x, int y, int root)
{
	if (x <= segtr[root].l && y >= segtr[root].r)
		return segtr[root].val;
	LL res = 0;
	push_down(root);
	if (x <= segtr[ls(root)].r)
		res += query(x, y, ls(root));
	if (y >= segtr[rs(root)].l)
		res += query(x, y, rs(root));
	return res;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
	build(1, 1, N);
	int o, x, y; LL k;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d%lld", &x, &y, &k);
			update(x, y, 1, k);
		}
		else
		{
			scanf("%d%d", &x, &y);
			LL res = query(x, y, 1);
			printf("%lld\n", res);
		}
	}
	return 0;
}