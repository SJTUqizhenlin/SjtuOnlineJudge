#include <stdio.h>
#include <queue>
using namespace std;

struct Point { 
	int x; int y; 
	Point(int xx, int yy):x(xx), y(yy) {}
};
int MapG[1200][1200];
queue<Point> q;

int main()
{
	int X, Y, N; scanf("%d%d%d", &X, &Y, &N);
	int tmpx, tmpy;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &tmpx, &tmpy);
		MapG[600 + tmpx][600 + tmpy] = -1;
	}
	int dx[4] = { -1,0,0,1 };
	int dy[4] = { 0,-1,1,0 };
	q.push(Point(600, 600));
	MapG[600][600] = 1;
	int step = 0, curx, cury, nxtx, nxty;
	while (MapG[600 + X][600 + Y] == 0)
	{
		curx = q.front().x; 
		cury = q.front().y;
		q.pop();
		for (int t = 0; t < 4; t++)
		{
			nxtx = dx[t] + curx;
			if (nxtx < 80 || nxtx > 1120) continue;
			nxty = dy[t] + cury;
			if (nxty < 80 || nxty > 1120) continue;
			if (MapG[nxtx][nxty] == 0)
			{
				MapG[nxtx][nxty] = MapG[curx][cury] + 1;
				q.push(Point(nxtx, nxty));
			}
		}
	}
	printf("%d", MapG[600 + X][600 + Y] - 1);
	return 0;
}