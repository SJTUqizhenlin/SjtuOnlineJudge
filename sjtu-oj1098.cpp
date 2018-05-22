#include <stdio.h>
using namespace std;

int G[101][101];

int main()
{
	int T; scanf("%d", &T);
	int n, m, u, v;
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= n; j++) G[i][j] = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			G[u][v] = G[v][u] = 1;
			G[u][0]++; G[v][0]++;
		}
		if (m == 0) { printf("NO ODD SUBGRAPH\n"); continue; }
		bool isOdd = true;
		for (int i = 1; i <= n; i++)
			if (G[i][0] % 2 == 0) { isOdd = false; break; }
		if (isOdd) { printf("ODD GRAPH\n"); continue; }
		printf("2 ");
		for (int i = 1; i <= n; i++)
		{
			if (G[i][0] > 0)
			{
				for (int j = i + 1; j <= n; j++)
					if (G[i][j]) { printf("%d %d\n", i, j); break; }
				break;
			}
		}
	}
	return 0;
}