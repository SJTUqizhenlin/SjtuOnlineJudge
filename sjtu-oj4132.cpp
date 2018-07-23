#include <stdio.h>
#include <string.h>
#define lson(x) ((x) << 1)
#define rson(x) (((x) << 1) + 1)
using namespace std;

int const maxN = 200000;
char s1[maxN + 5];
char s2[maxN + 5];
int N, M, Q, L;
struct segtr_node {
	int val, lbound, rbound;
	segtr_node()
		:val(0), lbound(0), rbound(0) {}
};
segtr_node segtr[maxN * 4 + 5];

void init_s() {
	scanf("%d%d", &N, &M);
	scanf("%s", &(s1[1]));
	scanf("%s", &(s2[1]));
	L = (M < N ? M : N);
	return;
}

void init_segtr(int nid, int lb, int rb) {
	segtr[nid].lbound = lb;
	segtr[nid].rbound = rb;
	if (rb == lb) {
		segtr[nid].val = (s1[lb] == s2[lb] ? 1 : 0);
		return;
	}
	int mid = (lb + rb) / 2;
	init_segtr(lson(nid), lb, mid);
	init_segtr(rson(nid), mid + 1, rb);
	segtr[nid].val = segtr[lson(nid)].val + segtr[rson(nid)].val;
	return;
}

void fix_segtr(int nid, int pos) {
	if (segtr[nid].lbound == segtr[nid].rbound) {
		segtr[nid].val = (s1[segtr[nid].lbound] == s2[segtr[nid].lbound] ? 1 : 0);
		return;
	}
	if (pos <= segtr[lson(nid)].rbound)
		fix_segtr(lson(nid), pos);
	else
		fix_segtr(rson(nid), pos);
	segtr[nid].val = segtr[lson(nid)].val + segtr[rson(nid)].val;
	return;
}

int findLCP(int nid) {
	if (segtr[nid].rbound == segtr[nid].lbound)
		return (segtr[nid].val);
	if (segtr[lson(nid)].val == (segtr[lson(nid)].rbound - segtr[lson(nid)].lbound + 1))
		return (segtr[lson(nid)].val + findLCP(rson(nid)));
	return findLCP(lson(nid));
}

void query() {
	scanf("%d", &Q);
	int op1, op2; char op3;
	int res;
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &op1, &op2);
		scanf("%c", &op3);
		while (!(op3 >= 'a' && op3 <= 'z'))
			scanf("%c", &op3);
		if (op1 == 0 && s1[op2] != op3) {
			s1[op2] = op3;
			fix_segtr(1, op2);
		}
		if (op1 == 1 && s2[op2] != op3) {
			s2[op2] = op3;
			fix_segtr(1, op2);
		}
		res = findLCP(1);
		printf("%d\n", res);
	}
	return;
}

int main() {
	init_s();
	init_segtr(1, 1, L);
	query();
	return 0;
}