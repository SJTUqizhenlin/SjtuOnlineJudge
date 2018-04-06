#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int *e = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &e[i]);
	sort(e, e + n);
	for (int i = 0; i < n; i++)
		printf("%d ", e[i]);
	printf("\n");
	return 0;
}