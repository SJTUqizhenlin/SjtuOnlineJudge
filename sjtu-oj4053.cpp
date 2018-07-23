// Naive permutation gets TLE, so use DFS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int isPrime(int x)
{
	if (x == 1) return 0;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

int primeArr[40];

void init_prime()
{
	for (int i = 1; i < n * 2 + 1; i++)
		primeArr[i] = isPrime(i);
	return;
}

int cnctArr[20][20];

void init_cnct()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cnctArr[i][j] = primeArr[i + j];
	return;
}

int visited[20];
int stkArr[20];
int Count_num = 0;

void dfs(int x, int dep)
{
	if (dep == n && cnctArr[stkArr[n]][stkArr[1]])
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", stkArr[i]);
		printf("\n"); return;
	}
	for (int i = 1; i <= n; i++)
		if (cnctArr[x][i] && !visited[i])
		{
			visited[i] = 1;
			stkArr[dep + 1] = i;
			dfs(i, dep + 1);
			visited[i] = 0;
		}
	return;
}

int main()
{
	scanf("%d", &n);
	if (n % 2 == 1) { printf("None\n"); return 0; }
	init_prime();
	init_cnct();
	visited[1] = 1;
	stkArr[1] = 1;
	dfs(1, 1);
	visited[1] = 0;
	return 0;
}