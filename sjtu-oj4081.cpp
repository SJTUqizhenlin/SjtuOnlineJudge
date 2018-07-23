#include <stdio.h>
#include <algorithm>
using namespace std;

long long arr[500005];
long long tar[500005];
long long Sum = 0;
int N, K;

void init()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &(arr[i]));
		Sum += arr[i];
	}
	make_heap(arr, arr + N);
	sort_heap(arr, arr + N);
	return;
}

int main()
{
	init();
	long long l = arr[0], r = Sum / N + 1, mid;
	long long times;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		times = 0;
		for (int i = 0; i < N; i++)
			if (arr[i] < mid) times += (mid - arr[i]);
		if (times <= K) l = mid;
		else r = mid;
	}
	long long lower = l;
	r = arr[N - 1]; l = Sum / N + (Sum % N == 0 ? 0 : 1) - 1;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		times = 0;
		for (int i = N - 1; i >= 0; i--)
			if (arr[i] > mid) times += (arr[i] - mid);
		if (times <= K) r = mid;
		else l = mid;
	}
	long long upper = r;
	printf("%lld\n", (upper - lower));
	return 0;
}