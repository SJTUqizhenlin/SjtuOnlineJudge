#include <stdio.h>
using namespace std;

int main()
{
	int n; char c;
	scanf("%c%d", &c, &n);
	for (int i = 1; i * 2  <= n + 1; i++)
	{
		for (int j = 1; j * 2 <= n - i * 2 + 1; j++)
			printf(" ");
		for (int j = 1; j <= i * 2 - 1; j++)
			printf("%c", c);
		printf("\n");
	}
	for (int i = n / 2 + 2; i <= n; i++)
	{
		for (int j = 1; j * 2 <= i * 2 - n - 1; j++)
			printf(" ");
		for (int j = 1; j <= 2 * n - 2 * i + 1; j++)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}