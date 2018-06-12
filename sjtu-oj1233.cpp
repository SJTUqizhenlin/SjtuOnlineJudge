#include <iostream>
using namespace std;

struct g_node
{
	int id; g_node *nxt;
	g_node() :id(0), nxt(nullptr) {}
	g_node(int iid) :id(iid), nxt(nullptr) {}
};

g_node g_arr[15];
int visited[15];
int n, m, M, start;

int dfs(int id, int dep)
{
	if (dep == M) return 1;
	g_node *cur = &(g_arr[id]);
	int res = 0;
	while (cur->nxt)
	{
		cur = cur->nxt;
		if (!visited[cur->id])
		{
			visited[cur->id] = 1;
			res += dfs(cur->id, dep + 1);
			visited[cur->id] = 0;
		}
	}
	return res;
}

int main()
{
	cin >> n >> m >> start >> M;
	for (int i = 1; i <= n; i++) g_arr[i].id = i;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		g_node *cur = &(g_arr[u]);
		while (cur->id != v && cur->nxt) cur = cur->nxt;
		if (cur->id == v) continue;
		g_node *nv = new g_node(v);
		cur->nxt = nv;
	}
	visited[start] = 1;
	int res = dfs(start, 0);
	visited[start] = 0;
	cout << res << endl;
	return 0;
}