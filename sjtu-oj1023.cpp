#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int arr[600][600];
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		if (b == 2)
		{
			for (int j = 0; j < a; j++)
			{
				for (int k = 0; k < a; k++)
				{
					scanf("%d", &arr[k][j]);
				}
			}
			for (int j = 0; j < a; j++)
			{
				for (int k = 0; k < a; k++)
				{
					printf("%d ", arr[j][k]);
				}
				printf("\n");
			}
		}
		if (b == 1)
		{
			for (int j = 0; j < a; j++)
			{
				for (int k = 0; k < a; k++)
				{
					scanf("%d", &arr[a - j - 1][k]);
				}
			}
			for (int j = 0; j < a; j++)
			{
				for (int k = 0; k < a; k++)
				{
					printf("%d ", arr[j][k]);
				}
				printf("\n");
			}
		}
		if (b == 0)
		{
			for (int j = 0; j < a; j++)
			{
				for (int k = 0; k < a; k++)
				{
					scanf("%d", &arr[j][a - k - 1]);
				}
			}
			for (int j = 0; j < a; j++)
			{
				for (int k = 0; k < a; k++)
				{
					printf("%d ", arr[j][k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}