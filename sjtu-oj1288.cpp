// this DFS is right, but gets TLE
#include <iostream>
using namespace std;

inline int Absolute(int x)
{
	if (x > 0) return x;
	else return (0 - x);
}

int MapArr[20][20];
int NumArr[20];
int visited[20];
int n, k;

long long dfs(int x, int dep)
{
	long long res = 0;
	if (dep == n) res = 1;
	else
	{
		for (int i = 1; i <= n; i++)
			if (MapArr[x][i] && !visited[i])
			{
				visited[i] = 1;
				res += dfs(i, dep + 1);
				visited[i] = 0;
			}
	}
	return res;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> NumArr[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (Absolute(NumArr[i] - NumArr[j]) > k)
				MapArr[i][j] = 1;
			else
				MapArr[i][j] = 0;
		}
		visited[i] = 0;
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 1;
		res += dfs(i, 1);
		visited[i] = 0;
	}
	cout << res << endl;
	return 0;
}