#include <stdio.h>
using namespace std;

const int MAXN = 50005;
int arr[MAXN];
int L, N, M;

void init_arr() {
	scanf("%d%d%d", &L, &N, &M);
	arr[0] = 0; arr[N + 1] = L;
	for (int i = 1; i <= N; i++) scanf("%d", &(arr[i]));
	return;
}

bool isPossible(int x) {
	int c = 0, cur = 0, nxt = 0;
	while (nxt <= N) {
		while (nxt <= N && arr[nxt] - arr[cur] < x) nxt++;
		c += (nxt - cur - 1);
		cur = nxt;
	}
	return (c <= M);
}

int main() {
	init_arr();
	if (N <= M) printf("%d\n", L);
	else {
		int l = 1, r = L, mid;
		while (r - l > 1) {
			mid = (l + r) >> 1;
			if (isPossible(mid)) l = mid;
			else r = mid;
		}
		printf("%d\n", l);
	}
	return 0;
}