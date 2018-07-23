#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

int g[101][101];
int flag[102][102];
int n, m;
int dist[6][6];

struct node
{
	int x, y;
	node(int xx, int yy) :x(xx), y(yy) {}
	bool operator==(const node& rhs) const
	{
		return (x == rhs.x) && (y == rhs.y);
	}
};

int minpath(node beg, node ed)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) flag[i][j] = 0;
	queue<node> q;
	q.push(node(beg.x, beg.y));
	flag[beg.x][beg.y] = 1;
	while (!q.empty())
	{
		node tmp = q.front();
		if (tmp == ed) return (flag[tmp.x][tmp.y] - 1);
		if (!flag[tmp.x - 1][tmp.y] && g[tmp.x - 1][tmp.y] != -1)
		{
			flag[tmp.x - 1][tmp.y] = flag[tmp.x][tmp.y] + 1;
			q.push(node(tmp.x - 1, tmp.y));
		}
		if (!flag[tmp.x + 1][tmp.y] && g[tmp.x + 1][tmp.y] != -1)
		{
			flag[tmp.x + 1][tmp.y] = flag[tmp.x][tmp.y] + 1;
			q.push(node(tmp.x + 1, tmp.y));
		}
		if (!flag[tmp.x][tmp.y - 1] && g[tmp.x][tmp.y - 1] != -1)
		{
			flag[tmp.x][tmp.y - 1] = flag[tmp.x][tmp.y] + 1;
			q.push(node(tmp.x, tmp.y - 1));
		}
		if (!flag[tmp.x][tmp.y + 1] && g[tmp.x][tmp.y + 1] != -1)
		{
			flag[tmp.x][tmp.y + 1] = flag[tmp.x][tmp.y] + 1;
			q.push(node(tmp.x, tmp.y + 1));
		}
		q.pop();
	}
	return -1;
}

int main()
{
	scanf("%d%d", &n, &m);
	vector<node> boxvec;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 2) boxvec.push_back(node(i, j));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 1) boxvec.push_back(node(i, j));
	for (int i = 0; i <= m + 1; i++) { flag[0][i] = 1; flag[n + 1][i] = 1; }
	for (int i = 0; i <= n + 1; i++) { flag[i][0] = 1; flag[m + 1][i] = 1; }
	for (int i = 0; i < boxvec.size() - 1; i++)
	{
		for (int j = i + 1; j < boxvec.size(); j++)
		{
			dist[i][j] = dist[j][i] = minpath(boxvec[i], boxvec[j]);
			if (dist[i][j] == -1)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	int res = INT32_MAX, ares = 0;
	vector<int> seqvec;
	for (int i = 0; i < boxvec.size() - 1; i++)
		seqvec.push_back(i + 1);
	do
	{
		ares = 0;
		ares += dist[0][seqvec[0]];
		for (int i = 0; i < seqvec.size() - 1; i++)
			ares += dist[seqvec[i]][seqvec[i + 1]];
		if (ares < res) res = ares;
	} while (next_permutation(seqvec.begin(), seqvec.end()));
	printf("%d\n", res);
	return 0;
}