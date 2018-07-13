#include <stdio.h>
using namespace std;
typedef long long LL;

const int MAXN = (1 << 17);
int N, P, M;
LL arr[MAXN];

struct segtr {
	LL val, mul, add;
	int lbound, rbound, leng;
	segtr()
		:val(0), mul(1), add(0), 
		lbound(0), rbound(0), leng(0) {}
};

segtr tr[MAXN * 4];

void build_tr(int root, int l, int r) {
	tr[root].lbound = l;
	tr[root].rbound = r;
	tr[root].leng = r - l + 1;
	if (l == r) tr[root].val = arr[l];
	else {
		int mid = (l + r) / 2;
		build_tr(root * 2, l, mid);
		build_tr(root * 2 + 1, mid + 1, r);
		tr[root].val = tr[root * 2].val + tr[root * 2 + 1].val;
	}
	tr[root].val %= P;
	return;
}

void push_down(int root) {
	// update sons' val
	tr[root * 2].val = tr[root * 2].val * tr[root].mul + tr[root * 2].leng * tr[root].add;
	tr[root * 2].val %= P;
	tr[root * 2 + 1].val = tr[root * 2 + 1].val * tr[root].mul + tr[root * 2 + 1].leng * tr[root].add;
	tr[root * 2 + 1].val %= P;
	//update sons' tag
	tr[root * 2].mul = (tr[root].mul * tr[root * 2].mul) % P;
	tr[root * 2 + 1].mul = (tr[root].mul * tr[root * 2 + 1].mul) % P;
	tr[root * 2].add = (tr[root].mul * tr[root * 2].add + tr[root].add) % P;
	tr[root * 2 + 1].add = (tr[root].mul * tr[root * 2 + 1].add + tr[root].add) % P;
	//reset root's tag
	tr[root].add = 0;
	tr[root].mul = 1;
	return;
}

void update1(int root, int l, int r, LL c) {
	if (l > tr[root].rbound || r < tr[root].lbound) return;
	if (l <= tr[root].lbound && r >= tr[root].rbound) {
		tr[root].val = (tr[root].val * c) % P;
		tr[root].mul = (tr[root].mul * c) % P;
		tr[root].add = (tr[root].add * c) % P;
		return;
	}
	push_down(root);
	update1(root * 2, l, r, c);
	update1(root * 2 + 1, l, r, c);
	tr[root].val = (tr[root * 2].val + tr[root * 2 + 1].val) % P;
	return;
}

void update2(int root, int l, int r, LL c) {
	if (l > tr[root].rbound || r < tr[root].lbound) return;
	if (l <= tr[root].lbound && r >= tr[root].rbound) {
		tr[root].val = (tr[root].val + c * tr[root].leng) % P;
		tr[root].add = (tr[root].add + c) % P;
		return;
	}
	push_down(root);
	update2(root * 2, l, r, c);
	update2(root * 2 + 1, l, r, c);
	tr[root].val = (tr[root * 2].val + tr[root * 2 + 1].val) % P;
	return;
}

LL query(int root, int l, int r) {
	if (l > tr[root].rbound || r < tr[root].lbound) return 0;
	if (l <= tr[root].lbound && r >= tr[root].rbound) return tr[root].val;
	push_down(root);
	return (query(root * 2, l, r) + query(root * 2 + 1, l, r)) % P;
}

int main() {
	scanf("%d%d", &N, &P);
	for (int i = 1; i <= N; i++) scanf("%lld", &(arr[i]));
	build_tr(1, 1, N);
	int odr, t, g; LL c;
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &odr);
		if (odr == 1) {
			scanf("%d%d%lld", &t, &g, &c);
			update1(1, t, g, c);
		}
		if (odr == 2) {
			scanf("%d%d%lld", &t, &g, &c);
			update2(1, t, g, c);
		}
		if (odr == 3) {
			scanf("%d%d", &t, &g);
			printf("%lld\n", query(1, t, g));
		}
	}
	return 0;
}