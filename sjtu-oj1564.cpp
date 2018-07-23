#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

int g[6][6];
int res[6][6];
int bx, by, ex, ey;

void setout(int x, int y, int cost, int state)
{
	res[x][y] = cost;
	if (x == ex && y == ey) return;
	if (x > 0)
		if (cost + state * g[x - 1][y] < res[x - 1][y])
			setout(x - 1, y, cost + state * g[x - 1][y], (state * g[x - 1][y]) % 4 + 1);
	if (y > 0)
		if (cost + state * g[x][y - 1] < res[x][y - 1])
			setout(x, y - 1, cost + state * g[x][y - 1], (state * g[x][y - 1]) % 4 + 1);
	if (x < 5)
		if (cost + state * g[x + 1][y] < res[x + 1][y])
			setout(x + 1, y, cost + state * g[x + 1][y], (state * g[x + 1][y]) % 4 + 1);
	if (y < 5)
		if (cost + state * g[x][y + 1] < res[x][y + 1])
			setout(x, y + 1, cost + state * g[x][y + 1], (state * g[x][y + 1]) % 4 + 1);
	return;
}

int main()
{
	int n;
	cin >> n;
	for (int times = 0; times < n; times++)
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
			{
				scanf("%d", &g[i][j]);
				res[i][j] = INT32_MAX;
			}
		cin >> bx >> by >> ex >> ey;
		int state = 1;
		int cost = 0;
		setout(bx, by, cost, state);
		cout << res[ex][ey] << endl;
	}
	return 0;
}