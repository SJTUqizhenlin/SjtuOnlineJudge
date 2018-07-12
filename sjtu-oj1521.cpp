#include <stdio.h>
using namespace std;

const int MaxN = 10000;
int rootof[2 * MaxN + 5];
int depth[2 * MaxN + 5];
int n, m;

void init() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
		scanf("%d", &(rootof[i]));
	for (int i = n + 1; i <= n + m; i++)
		scanf("%d", &(rootof[i]));
	return;
}

void findMaxPath(int &res) {
	for (int i = n + m; i > 1; i--) {
		if (depth[i] + 1 + depth[rootof[i]] > res)
			res = depth[i] + 1 + depth[rootof[i]];
		if (depth[i] + 1 > depth[rootof[i]])
			depth[rootof[i]] = depth[i] + 1;
	}
	return;
}

int main() {
	init();
	int res = 0;
	findMaxPath(res);
	printf("%d\n", res);
	return 0;
}