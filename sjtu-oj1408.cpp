#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 300005;

#define max(a, b) (a > b ? a : b);

struct g_node
{
	int no; g_node *next;
	g_node() :no(0), next(nullptr) {}
	g_node(int nno) :no(nno), next(nullptr) {}
};

g_node g_arr[maxn];
int ebeg[maxn], eend[maxn], ewgh[maxn];
int Rank[maxn];
int res[maxn];

bool cmp(int a, int b) { return ewgh[a] > ewgh[b]; }

int main()
{
	int N, M; scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &ebeg[i], &eend[i], &ewgh[i]);
		Rank[i] = i;
		res[i] = 1;
		g_node *tmp = new g_node(i);
		tmp->next = g_arr[ebeg[i]].next;
		g_arr[ebeg[i]].next = tmp;
	}
	sort(Rank + 1, Rank + M + 1, cmp);
	int maxres = 0;
	g_node* cur;
	for (int i = 1; i <= M; i++)
	{
		cur = g_arr[eend[Rank[i]]].next;
		while (cur)
		{
			if (ewgh[cur->no] > ewgh[Rank[i]])
				res[Rank[i]] = max(res[cur->no] + 1, res[Rank[i]]);
			cur = cur->next;
		}
		maxres = max(maxres, res[Rank[i]]);
	}
	printf("%d\n", maxres);
	return 0;
}