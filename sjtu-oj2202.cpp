#include <stdio.h>
#include <queue>

using namespace std;

int g[1005][1005], flag[1005][1005], upbnd[1005][1005];
int m, n, K;

void bfs(int x, int y)
{
	upbnd[x][y] = 2;
	queue<int> q; q.push(0);
	while (!q.empty())
	{
		x = q.front() / m + 1; y = q.front() % m + 1; q.pop();
		upbnd[x][y] = 2;
		if (x > 1 && flag[x - 1][y] && g[x - 1][y] == 0)
		{
			q.push((x - 2) * m + y - 1); flag[x - 1][y] = 0;
		}
		if (x < n && flag[x + 1][y] && g[x + 1][y] == 0)
		{
			q.push((x)* m + y - 1); flag[x + 1][y] = 0;
		}
		if (y > 1 && flag[x][y - 1] && g[x][y - 1] == 0)
		{
			q.push((x - 1) * m + y - 2); flag[x][y - 1] = 0;
		}
		if (y < m && flag[x][y + 1] && g[x][y + 1] == 0)
		{
			q.push((x - 1) * m + y); flag[x][y + 1] = 0;
		}
	}
}

bool dfs(int x, int y, int state)
{
	if (x == n && y == m) return true;
	flag[x][y] = 0;
	if (x > 1 && flag[x - 1][y] && state > g[x - 1][y])
		if (dfs(x - 1, y, state - g[x - 1][y])) return true;
	if (x < n && flag[x + 1][y] && state > g[x + 1][y])
		if (dfs(x + 1, y, state - g[x + 1][y])) return true;
	if (y > 1 && flag[x][y - 1] && state > g[x][y - 1])
		if (dfs(x, y - 1, state - g[x][y - 1])) return true;
	if (y < m && flag[x][y + 1] && state > g[x][y + 1])
		if (dfs(x, y + 1, state - g[x][y + 1])) return true;
	if (state < upbnd[x][y]) flag[x][y] = 1;
	return false;
}

int main()
{
	scanf("%d", &K);
	while (K--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &g[i][j]); /*g[i][j] = 0;*/ flag[i][j] = 1; upbnd[i][j] = 1;
			}
		/*g[1][2] = g[2][1] = g[n][m - 1] = g[n - 1][m] = 1;*/
		bfs(1, 1);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) flag[i][j] = 1;
		if (dfs(1, 1, 2)) printf("1\n"); else printf("0\n");
	}
	return 0;
}