#include <stdio.h>
#include <queue>
using namespace std;

struct gnode
{
	int no;
	gnode *next;
	gnode() :no(0), next(nullptr) {}
	gnode(int nno) :no(nno), next(nullptr) {}
};
int N, M;
gnode trarr[500005];
int trval[500005];
int tradd[500005];
int trprt[500005];
int visit[500005];

void ensure_tr()
{
	queue<int> q; q.push(1); visit[1] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		gnode *tmp = trarr[cur].next;
		while (tmp)
		{
			if (!visit[tmp->no])
			{
				visit[tmp->no] = 1;
				trprt[tmp->no] = trarr[cur].no;
				q.push(tmp->no);
			}
			tmp = tmp->next;
		}
	}
	return;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &trval[i]);
		trarr[i].no = i;
	}
	int u, v;
	for (int i = 1; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		gnode *tmpv = new gnode(v);
		tmpv->next = trarr[u].next;
		trarr[u].next = tmpv;
		gnode *tmpu = new gnode(u);
		tmpu->next = trarr[v].next;
		trarr[v].next = tmpu;
	}
	ensure_tr();
	int o1, o2, o3;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &o1);
		if (o1 == 1)
		{
			scanf("%d%d", &o2, &o3);
			tradd[o2] += o3;
		}
		if (o1 == 2)
		{
			scanf("%d", &o2);
			int res = trval[o2], sign = 1;
			while (o2)
			{
				res += tradd[o2] * sign;
				sign = 0 - sign;
				o2 = trprt[o2];
			}
			printf("%d\n", res);
		}
	}
	return 0;
}