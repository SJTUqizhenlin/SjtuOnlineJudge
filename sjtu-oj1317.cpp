#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[300];
int margin[300];

int main()
{
	int M, S, C;
	scanf("%d%d%d", &M, &S, &C);
	for (int i = 0; i < C; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + C);
	for (int i = 1; i < C; i++)
		margin[i] = arr[i] - arr[i - 1] - 1;
	sort(margin + 1, margin + C);
	int res;
	if (M < C)
	{
		res = arr[C - 1] - arr[0] + 1;
		for (int i = 1; i < M; i++)
			res -= margin[C - i];
	}
	else
	{
		res = C;
	}
	printf("%d\n", res);
	return 0;
}