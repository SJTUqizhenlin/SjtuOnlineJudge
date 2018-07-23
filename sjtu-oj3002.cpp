#include <stdio.h>

using namespace std;

int hashmap[1001];

int main()
{
	int n, tmp, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (!hashmap[tmp]) { hashmap[tmp] = 1; count++; }
	}
	printf("%d\n", count);
	for (int i = 1; i <= 1000; i++)
		if (hashmap[i]) printf("%d ", i);
	printf("\n");
	return 0;
}