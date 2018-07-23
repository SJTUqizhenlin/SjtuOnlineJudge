#include <stdio.h>
#include <algorithm>
#define lson(x) (x << 1)
#define rson(x) ((x << 1) + 1)
#define maxin(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct cow {
	int x, h;
	cow() :x(0), h(0) {}
	bool operator<(const cow &b) const {
		return x < b.x;
	}
};

struct segtrnode {
	int id, val, l, r;
	segtrnode() :val(0), l(0), r(0) {}
};

const int MAXN = 50000;
segtrnode segtr[MAXN * 4 + 5];
cow arr[MAXN + 5];
int n, d;

void init_arr() {
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &(arr[i].x), &(arr[i].h));
	sort(arr + 1, arr + n + 1);
	return;
}

void init_segtr(int id, int l, int r) {
	segtr[id].l = l;
	segtr[id].r = r;
	if (l == r) segtr[id].val = arr[l].h;
	else {
		int mid = (l + r) >> 1;
		init_segtr(lson(id), l, mid);
		init_segtr(rson(id), mid + 1, r);
		segtr[id].val = maxin(segtr[lson(id)].val, segtr[rson(id)].val);
	}
	return;
}

int findMax(int id, int lbound, int rbound) {
	if (segtr[id].l >= lbound && segtr[id].r <= rbound)
		return segtr[id].val;
	if (segtr[id].l > rbound || segtr[id].r < lbound)
		return 0;
	int lres = findMax(lson(id), lbound, rbound);
	int rres = findMax(rson(id), lbound, rbound);
	return maxin(lres, rres);
}

int main() {
	init_arr();
	init_segtr(1, 1, n);
	int lbound = 1, rbound = 1;
	int CountRes = 0;
	int lh, rh;
	for (int i = 1; i <= n; i++) {
		while (arr[lbound].x < arr[i].x - d && lbound < i)
			lbound++;
		while (arr[rbound + 1].x <= arr[i].x + d && rbound < n)
			rbound++;
		lh = 0; rh = 0;
		if (lbound < i) lh = findMax(1, lbound, i - 1);
		if (rbound > i) rh = findMax(1, i + 1, rbound);
		if (lh >= 2 * arr[i].h && rh >= 2 * arr[i].h)
			CountRes++;
	}
	printf("%d\n", CountRes);
	return 0;
}