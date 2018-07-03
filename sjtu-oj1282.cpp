#include <stdio.h>
#include <algorithm>
#include <stdint.h>
#define abso(x) ((x) > 0 ? (x) : -(x))
#define minin(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int MaxN = 2000;
int n;
int arr[MaxN + 5];
int arr1[MaxN + 5];
int dp1[MaxN + 5][MaxN + 5];
int dp2[MaxN + 5][MaxN + 5];

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &(arr[i]));
		arr1[i] = arr[i];
	}
	sort(arr1 + 1, arr1 + n + 1);
	return;
}

int sol() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp1[i][j] = dp2[i - 1][j] + abso(arr1[j] - arr[i]);
			dp2[i][j] = minin(dp1[i][j], (j == 1 ? INT32_MAX : (dp2[i][j - 1])));
		}
	}
	int ans = INT32_MAX;
	for (int i = 1; i <= n; ++i)
		ans = minin(ans, dp1[n][i]);
	return ans;
}


int main() {
	init();
	int res = INT32_MAX;
	int res1 = sol();
	if (res1 < res) res = res1;
	for (int i = 1; i <= (n / 2); i++) {
		int tmp = arr[i];
		arr[i] = arr[n + 1 - i];
		arr[n + 1 - i] = tmp;
	}
	int res2 = sol();
	if (res2 < res) res = res2;
	printf("%d\n", res);
	return 0;
}