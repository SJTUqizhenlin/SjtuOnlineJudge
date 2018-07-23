#include <stdio.h>
#include <queue>
using namespace std;

struct city {
	int id; city *next;
	city(int iid) :id(iid), next(nullptr) {}
};

city **arr;
int *visited;

void bfs(int root, long long &citys, long long &roads)
{
	queue<int> q;
	visited[root] = 1; q.push(root); citys++;
	while (!q.empty())
	{
		city *cur = arr[q.front()]->next;
		while (cur) {
			roads++;
			if (!visited[cur->id]) {
				visited[cur->id] = 1;
				q.push(cur->id); citys++;
			}
			cur = cur->next;
		}
		q.pop();
	}
	roads /= 2;
	return;
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	arr = new city*[N + 1];
	for (int i = 0; i <= N; i++) arr[i] = new city(i);
	int u, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		city *tmpu = new city(u), *tmpv = new city(v);
		tmpv->next = arr[u]->next; arr[u]->next = tmpv;
		tmpu->next = arr[v]->next; arr[v]->next = tmpu;
	}
	visited = new int[N + 1];
	long long citys, roads, res = 0;
	for (int i = 0; i <= N; i++) visited[i] = 0;
	for (int i = 0; i <= N; i++)
		if (visited[i] == 0) {
			citys = 0; roads = 0;
			bfs(i, citys, roads);
			res += ((citys * citys - citys) / 2 - roads);
		}
	printf("%lld\n", res);
	return 0;
}