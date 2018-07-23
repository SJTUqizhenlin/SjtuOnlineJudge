#include <stdio.h>
#include <algorithm>
using namespace std;

struct numNid {
	int val; int id;
	numNid() :val(0), id(0) {}
	bool operator<(const numNid &b) const {
		return (val < b.val);
	}
};

const int MAXN = 300000;
int segtr[MAXN + 1];
numNid arr[MAXN + 1];
int Rank[MAXN + 1];
int res[MAXN + 1];
int N, M;

int count_at(int x) {
	int ret = 0;
	x -= 1;
	while (x > 0) {
		ret += segtr[x];
		x -= (x & (-x));
	}
	return ret;
}

void add_at(int x) {
	while (x <= M) {
		segtr[x] += 1;
		x += (x & (-x));
	} return;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &(arr[i].val));
		arr[i].id = i;
	}
	sort(arr + 1, arr + N + 1);
	int ranknum = 1, iid = 1;
	Rank[arr[iid].id] = ranknum;
	while (++iid <= N) {
		if (arr[iid].val > arr[iid - 1].val) ranknum++;
		Rank[arr[iid].id] = ranknum;
	}
	M = ranknum;
	for (int i = N; i > 0; i--) {
		res[i] = count_at(Rank[i]);
		add_at(Rank[i]);
	}
	for (int i = 1; i <= N; i++) printf("%d ", res[i]);
	return 0;
}