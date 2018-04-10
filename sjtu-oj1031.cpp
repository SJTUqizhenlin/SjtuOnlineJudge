#include <iostream>
#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;

int maparr[101][101];
int N;
int min_h = 111;
int max_h = -1;
bool vis[201][201];

struct point
{
	int x;
	int y;
	point(int a, int b)
	{
		x = a;
		y = b;
	}
};

queue<point> q;

int ch_x[4] = { -1, 1, 0, 0 };
int ch_y[4] = { 0, 0, -1, 1 };

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &maparr[i][j]);
			if (maparr[i][j] > max_h) max_h = maparr[i][j];
			if (maparr[i][j] < min_h) min_h = maparr[i][j];
		}
}

bool bfs(int lower, int upper)
{
	if ((maparr[0][0] > upper || maparr[0][0] < lower) || (maparr[N - 1][N - 1] > upper || maparr[N - 1][N - 1] < lower))
		return false;
	memset(vis, false, sizeof(vis));
	while (!q.empty()) q.pop();
	point start(0, 0);
	q.push(start);
	while (!q.empty())
	{
		point cur = q.front();
		q.pop();
		vis[cur.x][cur.y] = true;
		for (int i = 0; i < 4; i++)
		{
			int newx = cur.x + ch_x[i];
			int newy = cur.y + ch_y[i];
			if (newx < 0 || newx >= N) continue;
			if (newy < 0 || newy >= N) continue;
			if (vis[newx][newy]) continue;
			if (maparr[newx][newy] > upper || maparr[newx][newy] < lower)
				continue;
			point newp(newx, newy);
			q.push(newp);
			vis[newx][newy] = true;
			if (vis[N - 1][N - 1]) return true;
		}
	}
	return false;
}

int bin_sear()
{
	int L = 0;
	int R = max_h - min_h;
	int mid;
	while (L < R)
	{
		mid = (L + R) / 2;
		bool b = false;
		for (int i = min_h; i <= max_h - mid; i++)
		{
			if (bfs(i, i + mid))
			{
				b = true;
				break;
			}
		}
		if (b) R = mid;
		else L = mid + 1;
	}
	return L;
}

int main()
{
	init();
	cout << bin_sear() << endl;
	return 0;
}