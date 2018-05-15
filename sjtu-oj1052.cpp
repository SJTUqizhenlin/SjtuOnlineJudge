#include <iostream>
#include <stdio.h>

using namespace std;

int setarr[100][201];

int main()
{
	int N;
	cin >> N;
	int numarr[100];
	for (int i = 0; i < N; i++)
		cin >> numarr[i];
	int tmpint;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < numarr[i]; j++)
		{
			scanf("%d", &tmpint);
			setarr[i][tmpint] = 1;
		}
	}
	int M, num1, num2;
	cin >> M;
	char order;
	for (int i = 0; i < M; i++)
	{
		cin >> order >> num1 >> num2;
		if (order == '+')
		{
			for (int j = 0; j <= 200; j++)
			{
				if (setarr[num2 - 1][j])
					setarr[num1 - 1][j] = 1;
			}
		}
		if (order == '-')
		{
			for (int j = 0; j <= 200; j++)
			{
				if (setarr[num2 - 1][j])
					if (setarr[num1 - 1][j])
						setarr[num1 - 1][j] = 0;
			}
		}
		if (order == '*')
		{
			for (int j = 0; j <= 200; j++)
			{
				if (setarr[num2 - 1][j])
				{
					if (setarr[num1 - 1][j])
						setarr[num1 - 1][j] = 2;
				}
			}
			for (int j = 0; j <= 200; j++)
			{
				if (setarr[num1 - 1][j] != 2)
					setarr[num1 - 1][j] = 0;
				else
					setarr[num1 - 1][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j <= 200; j++)
		{
			if (setarr[i][j])
				count++;
		}
		if (count)
			for (int j = 0; j <= 200; j++)
				if (setarr[i][j])
					printf("%d ", j);
		cout << '\n';
	}
	return 0;
}