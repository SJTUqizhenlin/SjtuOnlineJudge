//#include <stdio.h>
//#include <stdint.h>
//using namespace std;
//typedef long long LL;
//
//struct tr_node
//{
//	int no; LL wgh;
//	tr_node *next;
//	tr_node() :no(0), wgh(0), next(nullptr) {}
//	tr_node(int nno, LL wwgh) 
//		:no(nno), wgh(wwgh), next(nullptr) {}
//};
//
//tr_node tr[800010];
//int visit[800010];
//LL resof[800010];
//int u, v; LL w;
//
//void init_tr(int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		scanf("%d%d%lld", &u, &v, &w);
//		tr_node *tmpv = new tr_node(v, w);
//		tmpv->next = tr[u].next;
//		tr[u].next = tmpv;
//		tr_node *tmpu = new tr_node(u, w);
//		tmpu->next = tr[v].next;
//		tr[v].next = tmpu;
//		visit[i] = 0;
//	}
//	visit[n] = 0;
//	return;
//}
//
//void getres(int root)
//{
//	LL res = 0; visit[root] = 1; int countkid = 0;
//	tr_node *cur = tr[root].next;
//	while (cur)
//	{
//		if (!visit[cur->no])
//		{
//			resof[cur->no] = cur->wgh;
//			getres(cur->no);
//			countkid += 1;
//			res += resof[cur->no];
//		}
//		cur = cur->next;
//	}
//	if (countkid && res < resof[root])
//		resof[root] = res;
//	return;
//}
//
//int main()
//{
//	int n, root;
//	scanf("%d%d", &n, &root);
//	init_tr(n);
//	resof[root] = INT64_MAX;
//	getres(root);
//	printf("%lld\n", resof[root]);
//	return 0;
//}

//above recursive version causes a "Runtime Error"
//may be the depth of recursion is too large(maybe not XD)

#include <stdio.h>
#include <stack>
using namespace std;
typedef long long LL;

struct tr_node
{
	int no; LL wgh;
	tr_node *next;
	tr_node() :no(0), wgh(0), next(nullptr) {}
	tr_node(int nno, LL wwgh) 
		:no(nno), wgh(wwgh), next(nullptr) {}
};

tr_node tr[800010];
int visit[800010];
int dfsarr[800010];
int isleaf[800010];
LL resof[800010];
int n, root, u, v; LL w;

void init_tr()
{
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%lld", &u, &v, &w);
		tr_node *tmpv = new tr_node(v, w);
		tmpv->next = tr[u].next;
		tr[u].next = tmpv;
		tr_node *tmpu = new tr_node(u, w);
		tmpu->next = tr[v].next;
		tr[v].next = tmpu;
	}
	return;
}

void dfs(int r)
{
	stack<int> stk; 
	stk.push(r); visit[r] = 1;
	int p = 0, topno = 0;
	while (!stk.empty())
	{
		topno = stk.top();
		tr_node *cur = tr[topno].next;
		while (cur)
		{
			if (!visit[cur->no])
			{
				stk.push(cur->no);
				visit[cur->no] = 1;
			}
			cur = cur->next;
		}
		if (stk.top() == topno)
		{
			dfsarr[++p] = stk.top();
			stk.pop();
		}
	}
	return;
}

int main()
{
	scanf("%d%d", &n, &root);
	init_tr();
	for (int i = 1; i <= n; i++) visit[i] = 0;
	dfs(root);
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
		resof[i] = 0;
		isleaf[i] = 0;
	}
	int x, kidnum;
	for (int i = 1; i <= n; i++)
	{
		x = dfsarr[i]; visit[x] = 1;
		kidnum = 0;
		tr_node *cur = tr[x].next;
		while (cur)
		{
			if (visit[cur->no])
			{
				if (isleaf[cur->no]) 
					resof[x] += cur->wgh;
				else
					resof[x] += (cur->wgh < resof[cur->no] ? cur->wgh : resof[cur->no]);
				kidnum++;
			}
			cur = cur->next;
		}
		if (kidnum == 0) isleaf[x] = 1;
	}
	printf("%lld\n", resof[root]);
	return 0;
}