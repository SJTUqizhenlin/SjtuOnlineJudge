#include <stdio.h>
#include <queue>

using namespace std;

struct g_node
{
	int no;
	g_node* next;
	g_node() :no(-1), next(nullptr) {}
	g_node(int nono) :no(nono), next(nullptr) {}
};

void SetupG(g_node* g, int N)
{
	int x, y;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &x, &y);
		g_node* nx = new g_node(x);
		g_node* ny = new g_node(y);
		nx->next = g[y].next;
		g[y].next = nx;
		ny->next = g[x].next;
		g[x].next = ny;
	}
	return;
}

void EnsureG(g_node* g, int Root, int* depof)
{
	queue<int> q;
	q.push(Root);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		g_node* cur = &g[tmp];
		while (cur->next)
		{
			if (depof[cur->next->no] >= 0) cur->next = cur->next->next;
			else
			{
				depof[cur->next->no] = depof[tmp] + 1;
				q.push(cur->next->no);
				cur = cur->next;
			}
		}
	}
	return;
}

void Findmson(g_node* g, int* mson, int N)
{
	for (int Root = 0; Root < N; Root++)
	{
		if (!g[Root].next) continue;
		g_node* cur = g[Root].next;
		while (cur)
		{
			if (cur->no > mson[Root]) mson[Root] = cur->no;
			cur = cur->next;
		}
	}
	return;
}

void Query(int* mson)
{
	int Q, u;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &u);
		printf("%d\n", mson[u]);
	}
	return;
}

int main()
{
	int N, R;
	scanf("%d%d", &N, &R);

	g_node* g = new g_node[N];
	SetupG(g, N);

	int* depof = new int[N];
	for (int i = 0; i < N; i++) depof[i] = -1;
	depof[R] = 0;
	EnsureG(g, R, depof);
	
	int* maxson = new int[N];
	for (int i = 0; i < N; i++) maxson[i] = -1;
	Findmson(g, maxson, N);

	Query(maxson);
	return 0;
}