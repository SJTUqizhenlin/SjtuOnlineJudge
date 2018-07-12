#include <stdio.h>
using namespace std;

const int MaxN = 3000000;
int arr[MaxN + 5];
int n, k;

int nextInt() {
	int ret = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}

void init() {
	n = nextInt(); k = nextInt();
	for (int i = 0; i < n; i++)
		arr[i] = nextInt();
	return;
}

void exchange(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
	return;
}

int partition1(int l, int r) {
	int ret = l - 1;
	for (int i = l; i <= r; i++) {
		if (arr[i] < arr[r]) {
			++ret;
			exchange(arr[i], arr[ret]);
		}
	} return ret;
}

int partition2(int l, int r) {
	int ret = l - 1;
	for (int i = l; i <= r; i++) {
		if (arr[i] <= arr[r]) {
			++ret;
			exchange(arr[i], arr[ret]);
		}
	} return ret;
}

int fastFind(int k, int l, int r) {
	int p1 = partition1(l, r);
	int p2 = partition2(p1 + 1, r);
	if (p1 - l + 1 < k && p2 - l + 1 >= k) return (arr[p2]);
	else {
		if (p1 - l + 1 >= k) return fastFind(k, l, p1);
		else return fastFind(k - (p2 - l + 1), p2 + 1, r);
	}
}

int main() {
	init();
	int res = fastFind(k, 0, n - 1);
	printf("%d\n", res);
	return 0;
}