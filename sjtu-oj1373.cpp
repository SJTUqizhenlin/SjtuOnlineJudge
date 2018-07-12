#include <stdio.h>
#include <queue>
#include <stdint.h>
using namespace std;

long long Maph[510][510];
int Mapf[510][510];
int visited[510][510];
int m, n;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int flagnum, begx, begy;

void init()
{
	scanf("%d%d", &m, &n);
	flagnum = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) scanf("%lld", &Maph[i][j]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &Mapf[i][j]);
			if (Mapf[i][j]) {
				flagnum++; begx = i; begy = j;
			}
		}
	return;
}

void zeroVisited()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			visited[i][j] = 0;
	return;
}

bool isOk(long long x)
{
	int fn = 0; zeroVisited();
	queue<int> qx; queue<int> qy;
	qx.push(begx); qy.push(begy);
	visited[begx][begy] = 1;
	fn++; int nx, ny;
	while (!qx.empty() && fn < flagnum)
	{
		for (int d = 0; d < 4; d++)
		{
			nx = qx.front() + dx[d];
			ny = qy.front() + dy[d];
			if (nx < 1 || nx > m || ny < 1 || ny > n) continue; 
			if (visited[nx][ny]) continue;
			if (Maph[nx][ny] - Maph[qx.front()][qy.front()] > x) continue;
			if (Maph[qx.front()][qy.front()] - Maph[nx][ny] > x) continue;
			visited[nx][ny] = 1;
			qx.push(nx);
			qy.push(ny);
			if (Mapf[nx][ny]) fn++;
		}
		qx.pop(); qy.pop();
	}
	if (fn == flagnum) return true;
	else return false;
}

long long binSearch(long long &lower, long long &upper)
{
	long long mid;
	while (upper > lower + 1)
	{
		mid = (upper + lower) / 2;
		if (isOk(mid))
			upper = mid;
		else
			lower = mid;
	}
	return upper;
}

int main()
{
	init();
	long long upper = (long long)INT32_MAX * 2 + 1;
	long long lower = -1;
	long long res = binSearch(lower, upper);
	printf("%lld", res);
	return 0;
}
