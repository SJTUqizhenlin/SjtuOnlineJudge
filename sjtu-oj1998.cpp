#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N; scanf("%d", &N);
	int *arr = new int[N + 1];
	for (int i = 1; i <= N; i++) scanf("%d", &(arr[i]));
	sort(arr + 1, arr + N + 1);
	int mid = arr[N / 2 + 1];
	int res = 0;
	for (int i = 1; i <= N; i++)
		res += (arr[i] > mid ? arr[i] - mid : mid - arr[i]);
	printf("%d\n", res);
	return 0;
}