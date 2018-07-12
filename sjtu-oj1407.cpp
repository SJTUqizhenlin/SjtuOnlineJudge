#include <stdio.h>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;

int main()
{
	int N, K; scanf("%d%d", &N, &K);
	LL *arr = new LL[N];
	int *flag = new int[N];
	for (int i = 0; i < N; i++) scanf("%lld", &(arr[i]));
	sort(arr, arr + N);
	for (int i = N - 1; i >= 0; i--) flag[i] = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (flag[i] == -1) continue;
		flag[i] = 1;
		LL *p = lower_bound(arr, arr + i, arr[i] / K);
		if ((*p) * K == arr[i]) flag[p - arr] = -1;
	}
	int res = 0;
	for (int i = 0; i < N; i++)
		if (flag[i] == 1) res++;
	printf("%d\n", res);
	return 0;
}