#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int sum_BIT(long long *BIT, int n)
{
	long long res = 0;
	while (n > 0)
	{
		res += *(BIT + n);
		n -= n & (-n);
	}
	return res;
}

void add_BIT(long long *BIT, int n, int num, int size)
{
	while (n <= size)
	{
		*(BIT + n) += num;
		n += n & (-n);
	}
}

int main()
{
	int N;
	cin >> N;
	int *arr = new int[N];
	long long *BIT = new long long[N + 1];
	memset(BIT, 0, sizeof(long long) * (N + 1));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	long long res = 0;
	for (int i = 0; i < N; i++)
	{
		res += (i - sum_BIT(BIT, arr[i]));
		add_BIT(BIT, arr[i], 1, N);
	}
	cout << res << endl;
	return 0;
}