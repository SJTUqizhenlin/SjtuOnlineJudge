#include <stdio.h>
using namespace std;

int arr[100005];

void count_num(int x, int &Count)
{
	while (x)
	{
		if (x % 2) ++Count;
		x >>= 1;
	}
	return;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int Count = 0;
	for (int i = 0; i < n; i++) count_num(arr[i], Count);
	printf("%d\n", Count);
	return 0;
}