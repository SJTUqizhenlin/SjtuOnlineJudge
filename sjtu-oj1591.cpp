#include <stdio.h>
using namespace std;
typedef long long LL;

struct node {
	int id; node *next;
	node() :id(0), next(nullptr) {}
	node(int iid) :id(iid), next(nullptr) {}
};

node nodearr[50005];
int visited[50005];
LL *value;
LL **sumofd;
int N, Q;
int maxdep = 1001;

void init_tree()
{
	scanf("%d%d", &N, &Q);
	if (N > 1005) maxdep = 101;
	value = new LL[N + 5]; for (int j = 0; j < N + 5; j++) value[j] = 0;
	sumofd = new LL*[N + 5];
	for (int i = 0; i < N + 5; i++)
	{
		sumofd[i] = new LL[maxdep + 5];
		for (int j = 0; j < maxdep + 5; j++) sumofd[i][j] = 0;
	}
	for (int i = 1; i <= N; i++) scanf("%lld", &value[i]);
	int u, v;
	for (int i = 1; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		node *tmpu = new node(u);
		node *tmpv = new node(v);
		tmpu->next = nodearr[v].next;
		nodearr[v].next = tmpu;
		tmpv->next = nodearr[u].next;
		nodearr[u].next = tmpv;
	}
	return;
}

void dfs(int root)
{
	sumofd[root][0] = value[root];
	node *cur = nodearr[root].next;
	while (cur)
	{
		if (!visited[cur->id]) {
			visited[cur->id] = 1;
			dfs(cur->id);
			sumofd[root][maxdep] += (sumofd[cur->id][maxdep - 1] + sumofd[cur->id][maxdep]);
			for (int i = maxdep - 1; i > 0; i--)
				sumofd[root][i] += sumofd[cur->id][i - 1];
			sumofd[root][0] += sumofd[cur->id][0];
		}
		cur = cur->next;
	}
	return;
}

void query()
{
	int id, dep;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d%d", &id, &dep);
		printf("%lld\n", sumofd[id][dep]);
	}
	return;
}

int main()
{
	init_tree();
	visited[1] = 1;
	dfs(1);
	query();
	return 0;
}