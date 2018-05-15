/*

This got a WrongAnswer result...
But I really don't know why ~(-_-!)~

*/



#include <iostream>
#include <stdio.h>

using namespace std;

int rou[511][511];
long long m[511][511];
long long mx[511][511];
long long my[511][511];
char line[511];
int T, R, C;

long long aichimi_sum_m(int x, int y, int a)
{
	long long sum = 0;
	sum = sum + m[x + a - 1][y + a - 1] - m[x + a - 1][y - 1] 
		- m[x - 1][y + a - 1] + m[x - 1][y - 1];
	sum = sum - rou[x][y] - rou[x][y + a - 1] - rou[x + a - 1][y] - rou[x + a - 1][y + a - 1];
	return sum;
}

long long aichimi_sum_mx(int x, int y, int a)
{
	long long sum = 0;
	sum = sum + mx[x + a - 1][y + a - 1] - mx[x + a - 1][y - 1]
		- mx[x - 1][y + a - 1] + mx[x - 1][y - 1];
	sum = sum - x * rou[x][y] - x * rou[x][y + a - 1] 
		- (x + a - 1) * rou[x + a - 1][y] - (x + a - 1) * rou[x + a - 1][y + a - 1];
	return sum;
}

long long aichimi_sum_my(int x, int y, int a)
{
	long long sum = 0;
	sum = sum + my[x + a - 1][y + a - 1] - my[x + a - 1][y - 1]
		- my[x - 1][y + a - 1] + my[x - 1][y - 1];
	sum = sum - y * rou[x][y] - (y + a - 1) * rou[x][y + a - 1] 
		- y * rou[x + a - 1][y] - (y + a - 1) * rou[x + a - 1][y + a - 1];
	return sum;
}

bool canFind(int a)
{
	for (int i = 1; i + a - 1 <= R; i++)
	{
		for (int j = 1; j + a - 1 <= C; j++)
			if (aichimi_sum_m(i, j, a) * (i + i + a - 1) == aichimi_sum_mx(i, j, a) * 2 &&
				aichimi_sum_m(i, j, a) * (j + j + a - 1) == aichimi_sum_my(i, j, a) * 2)
				return true;
	}
	return false;
}

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		scanf("%d%d", &R, &C);
		for (int i = 1; i <= R; i++)
		{
			scanf("%s", line);
			for (int j = 1; j <= C; j++)
				rou[i][j] = line[j - 1] - '0';
		}
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
			{
				m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1] + rou[i][j];
				mx[i][j] = mx[i - 1][j] + mx[i][j - 1] - mx[i - 1][j - 1] + i * rou[i][j];
				my[i][j] = my[i - 1][j] + my[i][j - 1] - my[i - 1][j - 1] + j * rou[i][j];
			}
		int res = 2;
		for (int tr = (R < C ? R : C); tr > 2; tr--)
			if (canFind(tr))
			{
				res = tr;
				break;
			}
		if (res == 2) printf("IMPOSSIBLE\n");
		else printf("%d\n", res);
	}
	return 0;
}
