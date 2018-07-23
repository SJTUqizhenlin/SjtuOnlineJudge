#include <stdio.h>

using namespace std;

struct node
{
	int no;
	node* next;
	node() :no(0), next(nullptr) {}
	node(int nono) :no(nono), next(nullptr) {}
};

const int maxn = 150005;
int n, m, a, b;
int flag[maxn];

void dfs(int x, node* g, long long &Count)
{
	flag[x] = 1;
	Count++;
	node* cur = g[x].next;
	while (cur)
	{
		if (!flag[cur->no]) dfs(cur->no, g, Count);
		cur = cur->next;
	}
	return;
}

int main()
{
	scanf("%d%d", &n, &m);
	node* g = new node[n + 1];
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		node* anew = new node(a);
		node* bnew = new node(b);
		bnew->next = g[a].next;
		g[a].next = bnew;
		anew->next = g[b].next;
		g[b].next = anew;
	}
	long long Count, res = 0;
	for (int i = 1; i <= n; i++)
	{
		Count = 0;
		if (!flag[i])
			dfs(i, g, Count);
		res += (Count * (Count - 1)) / 2;
	}
	if (res == m) printf("YES\n");
	else printf("NO\n");
	return 0;
}