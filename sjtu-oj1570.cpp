#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int search(int query, int *arr, int beg, int ed)
{
	if (ed - beg <= 1)
	{
		if (*(arr + beg) > query && *(arr + beg - 1) <= query)
			return beg;
		else return ed;
	}
	int mid = (beg + ed) / 2;
	if (*(arr + mid) > query && *(arr + mid - 1) <= query) return mid;
	else
	{
		if (*(arr + mid) <= query)
		{
			return search(query, arr, mid + 1, ed);
		}
		else
		{
			return search(query, arr, beg, mid - 1);
		}
	}
}

int main()
{
	int N, T;
	cin >> N >> T;
	int *arr = new int[N + 2];
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	arr[0] = INT_MIN;
	arr[N + 1] = INT_MAX;
	int query;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &query);
		int res = search(query, arr, 1, N + 1);
		printf("%d\n", N - res + 1);
	}
	return 0;
}