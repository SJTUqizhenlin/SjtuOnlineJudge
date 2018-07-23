#include <stdio.h>
#include <queue>
using namespace std;

const int MaxTime = 1000000;
int MapArr[305][305];
int stateArr[305][305][7];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int n, m;
int begx, begy, endx, endy;

bool KeepGo(int i, int j)
{
	for (int k = 6; k >= 2; k--)
		if (stateArr[i][j][k] < MaxTime)
			return true;
	return false;
}

void init()
{
	scanf("%d%d", &n, &m);
	int i, j, k;
	for (j = 0; j <= m + 1; j++)
	{
		MapArr[0][j] = 0;
		MapArr[n + 1][j] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		MapArr[i][0] = MapArr[i][m + 1] = 0;
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &MapArr[i][j]);
			if (MapArr[i][j] == 2) {
				begx = i; begy = j;
			}
			if (MapArr[i][j] == 3) {
				endx = i; endy = j;
			}
			for (k = 1; k <= 6; k++)
				stateArr[i][j][k] = MaxTime;
		}
	}
	return;
}

int main()
{
	init();
	stateArr[begx][begy][6] = 0;
	queue<int> quex; queue<int> quey;
	quex.push(begx); quey.push(begy);
	int curx, cury;
	int dnum, nextx, nexty;
	int k, pre_min;
	bool boo;
	while (!quex.empty())
	{
		curx = quex.front();
		cury = quey.front();
		if (KeepGo(curx, cury))
			for (dnum = 0; dnum < 4; dnum++)
			{
				nextx = curx + dx[dnum];
				nexty = cury + dy[dnum];
				if (MapArr[nextx][nexty] > 0)
				{
					if (MapArr[nextx][nexty] == 4)
					{
						pre_min = stateArr[curx][cury][2];
						for (k = 3; k <= 6; k++)
							if (stateArr[curx][cury][k] < pre_min)
								pre_min = stateArr[curx][cury][k];
						if (pre_min + 1 < stateArr[nextx][nexty][6])
						{
							stateArr[nextx][nexty][6] = pre_min + 1;
							quex.push(nextx); quey.push(nexty);
						}
					}
					else
					{
						boo = false;
						for (k = 6; k >= 2; k--)
						{
							if (stateArr[curx][cury][k] < MaxTime)
								if (stateArr[curx][cury][k] + 1 < stateArr[nextx][nexty][k - 1])
								{
									stateArr[nextx][nexty][k - 1] = stateArr[curx][cury][k] + 1;
									boo = true;
								}
						}
						if (boo) { quex.push(nextx); quey.push(nexty); }
					}
				}
			}
		quex.pop(); quey.pop();
	}
	int res = stateArr[endx][endy][1];
	for (k = 2; k <= 6; k++)
		if (res > stateArr[endx][endy][k])
			res = stateArr[endx][endy][k];
	if (res < MaxTime) printf("%d\n", res);
	else printf("-1\n");
	return 0;
}