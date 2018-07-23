#include <stdio.h>
#include <queue>

using namespace std;

int Map[500][500];
int n, m;

struct node { int x, y; node(int xx, int yy) :x(xx), y(yy) {} };

void Read_Map()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &Map[i][j]);
	return;
}

void bfs(int i, int j, int Count)
{
	queue<node> q;
	q.push(node(i, j)); Map[i][j] = Count;
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if (tmp.x > 0 && Map[tmp.x - 1][tmp.y] == 0) { q.push(node(tmp.x - 1, tmp.y)); Map[tmp.x - 1][tmp.y] = Count; }
		if (tmp.y > 0 && Map[tmp.x][tmp.y - 1] == 0) { q.push(node(tmp.x, tmp.y - 1)); Map[tmp.x][tmp.y - 1] = Count; }
		if (tmp.x < n - 1 && Map[tmp.x + 1][tmp.y] == 0) { q.push(node(tmp.x + 1, tmp.y)); Map[tmp.x + 1][tmp.y] = Count; }
		if (tmp.y < m - 1 && Map[tmp.x][tmp.y + 1] == 0) { q.push(node(tmp.x, tmp.y + 1)); Map[tmp.x][tmp.y + 1] = Count; }
	}
}

void Count_Ctry(int &Count)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (Map[i][j] == 0) { ++Count; bfs(i, j, Count); }
	return;
}

int main()
{
	Read_Map();
	int Count = 0;
	Count_Ctry(Count);
	printf("%d\n", Count);
	return 0;
}