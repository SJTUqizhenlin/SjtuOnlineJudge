#include <stdio.h>
typedef long long LL;
using namespace std;

const int MAXN = 100005;
LL arr0[MAXN];
int N, Q;

struct trnode {
	LL val, tag;
	int l, r, len;
	trnode()
		:val(0), tag(0), l(0), r(0), len(0) {}
};

trnode segtr[MAXN * 4];

void build_tr(int root, int lb, int rb) {
	segtr[root].l = lb; segtr[root].r = rb;
	segtr[root].len = rb - lb + 1;
	if (lb == rb) segtr[root].val = arr0[lb];
	else {
		int mid = (lb + rb) / 2;
		build_tr(root * 2, lb, mid);
		build_tr(root * 2 + 1, mid + 1, rb);
		segtr[root].val = segtr[root * 2].val + segtr[root * 2 + 1].val;
	}
	return;
}

void pushDown(int root) {
	segtr[root * 2].tag += segtr[root].tag;
	segtr[root * 2].val = segtr[root * 2].val + 
		segtr[root].tag * segtr[root * 2].len;
	segtr[root * 2 + 1].tag += segtr[root].tag;
	segtr[root * 2 + 1].val = segtr[root * 2 + 1].val + 
		segtr[root].tag * segtr[root * 2 + 1].len;
	segtr[root].tag = 0;
	return;
}

void updateAt(int root, int lb, int rb, LL k) {
	if (segtr[root].l > rb || segtr[root].r < lb) return;
	if (segtr[root].l >= lb && segtr[root].r <= rb) {
		segtr[root].val += k * segtr[root].len;
		segtr[root].tag += k;
		return;
	}
	pushDown(root);
	updateAt(root * 2, lb, rb, k);
	updateAt(root * 2 + 1, lb, rb, k);
	segtr[root].val = segtr[root * 2].val + segtr[root * 2 + 1].val;
	return;
}

LL queryAt(int root, int lb, int rb) {
	if (segtr[root].l > rb || segtr[root].r < lb) return 0;
	if (segtr[root].l >= lb && segtr[root].r <= rb) return segtr[root].val;
	pushDown(root);
	LL lres = queryAt(root * 2, lb, rb);
	LL rres = queryAt(root * 2 + 1, lb, rb);
	return (lres + rres);
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) scanf("%lld", &(arr0[i]));
	build_tr(1, 1, N);
	char OP = 0; int a, b; LL c;
	for (int i = 0; i < Q; i++) {
		scanf("%c", &OP);
		while (!(OP == 'Q' || OP == 'C')) scanf("%c", &OP);
		if (OP == 'C') {
			scanf("%d%d%lld", &a, &b, &c);
			updateAt(1, a, b, c);
		}
		if (OP == 'Q') {
			scanf("%d%d", &a, &b);
			LL res = queryAt(1, a, b);
			printf("%lld\n", res);
		}
	}
	return 0;
}