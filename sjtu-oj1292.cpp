#include <stdio.h>
using namespace std;

const int maxN = 1000000;
int hashset[maxN + 1];
int arr[maxN + 1];
int n; char c;

int readint() {
	c = getchar();
	while (!(c <= '9' && c >= '0')) c = getchar();
	int ret = 0;
	while (c <= '9' && c >= '0') {
		ret = ret * 10 + c - '0';
		c = getchar();
	} return ret;
}

void init() {
	for (int i = 1; i <= n; i++) {
		arr[i] = readint();
		hashset[i] = 0;
	}
	return;
}

int main() {
	while (scanf("%d", &n) > 0) {
		init();
		int res1 = 0, res2 = 0, cur, tmpres1;
		for (int i = 1; i <= n; i++) {
			tmpres1 = 0; cur = i;
			while (hashset[cur] == 0) {
				hashset[cur] = 1;
				++tmpres1;
				cur = arr[cur];
			}
			if (tmpres1 > 1) {
				res1 += (tmpres1 - 1);
				if (tmpres1 == 2 && res2 == 0) res2 = 1;
				if (tmpres1 > 2) res2 = 2;
			}
		}
		printf("%d\n%d\n", res1, res2);
	}
	return 0;
}