#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10005];

bool cmp(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	make_heap(arr, arr + n, cmp);
	int res = 0;
	for (int i = 0; i < n - 1; i++)
	{
		pop_heap(arr, arr + n - i, cmp);
		pop_heap(arr, arr + n - i - 1, cmp);
		res += arr[n - 1 - i] + arr[n - 2 - i];
		arr[n - 2 - i] += arr[n - 1 - i];
		push_heap(arr, arr + n - i - 1, cmp);
	}
	printf("%d\n", res);
	return 0;
}