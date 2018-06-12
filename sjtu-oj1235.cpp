#include <stdio.h>
#include <stdint.h>
#include <stack>
using namespace std;

long long min(long long x, long long y) { return (x < y ? x : y); }

struct g_node
{
	int no, wght;
	g_node *next;
	g_node() :no(0), wght(0), next(nullptr) {}
	g_node(int nno, int wwght) :no(nno), wght(wwght), next(nullptr) {}
};

g_node g_arr[10005];

void add_edge(int u, int v, int w)
{
	g_node *newv = new g_node(v, w);
	newv->next = g_arr[u].next;
	g_arr[u].next = newv;
	return;
}

bool visited[10005];
int preofid[10005];
int edgesofid[10005];
int Rrank[10005];
int Rrankofid[10005];
long long disofid[10005];

void init_Rrank(int n)
{
	for (int i = 1; i <= n; i++)
	{
		edgesofid[i] = INT32_MAX;
		Rrank[i] = i;
		Rrankofid[i] = i;
		disofid[i] = INT64_MAX;
	}
}

void swap(int &x, int &y) { int tmp = x; x = y; y = tmp; return; }

void Rrank_pop(int &size)
{
	swap(Rrank[1], Rrank[size]);
	swap(Rrankofid[Rrank[1]], Rrankofid[Rrank[size]]);
	--size;
	int cur = 1;
	while (true)
	{
		if (cur * 2 > size) break;
		if (cur * 2 + 1 > size)
		{
			if (disofid[Rrank[cur]] > disofid[Rrank[cur * 2]])
			{
				swap(Rrank[cur], Rrank[cur * 2]);
				swap(Rrankofid[Rrank[cur]], Rrankofid[Rrank[cur * 2]]);
			}
			break;
		}
		if (disofid[Rrank[cur]] <= min(disofid[Rrank[cur * 2]], disofid[Rrank[cur * 2 + 1]])) break;
		else
		{
			if (disofid[Rrank[cur * 2]] < disofid[Rrank[cur * 2 + 1]])
			{
				swap(Rrank[cur], Rrank[cur * 2]);
				swap(Rrankofid[Rrank[cur]], Rrankofid[Rrank[cur * 2]]);
				cur = cur * 2;
			}
			else
			{
				swap(Rrank[cur], Rrank[cur * 2 + 1]);
				swap(Rrankofid[Rrank[cur]], Rrankofid[Rrank[cur * 2 + 1]]);
				cur = cur * 2 + 1;
			}
		}
	}
	return;
}

void up_adjust(int x)
{
	while (x > 1)
	{
		if (disofid[Rrank[x]] < disofid[Rrank[x / 2]])
		{
			swap(Rrank[x], Rrank[x / 2]);
			swap(Rrankofid[Rrank[x]], Rrankofid[Rrank[x / 2]]);
			x /= 2;
		}
		else break;
	}
	return;
}

void reduce_dis_edge(int headid, int linkid, int w)
{
	if (disofid[headid] + w < disofid[linkid])
	{
		disofid[linkid] = disofid[headid] + w;
		edgesofid[linkid] = edgesofid[headid] + 1;
		preofid[linkid] = headid;
		up_adjust(Rrankofid[linkid]);
	}
	else
	{
		if (disofid[headid] + w == disofid[linkid] && edgesofid[linkid] > edgesofid[headid])
		{
			edgesofid[linkid] = edgesofid[headid] + 1;
			preofid[linkid] = headid;
		}
	}
	return;
}

int main()
{
	int n, m, start, end;
	scanf("%d%d%d%d", &n, &m, &start, &end);
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		if (v != u) add_edge(u, v, w);
	}
	init_Rrank(n);
	int Rrank_size = n;
	visited[start] = true;
	disofid[start] = 0;
	swap(Rrank[1], Rrank[start]);
	swap(Rrankofid[Rrank[1]], Rrankofid[Rrank[start]]);
	int topid;
	while (!visited[end])
	{
		topid = Rrank[1];
		Rrank_pop(Rrank_size);
		g_node *tmp = g_arr[topid].next;
		while (tmp)
		{
			if (!visited[tmp->no]) reduce_dis_edge(topid, tmp->no, tmp->wght);
			tmp = tmp->next;
		}
		visited[Rrank[1]] = true;
	}
	printf("%lld\n", disofid[end]);
	stack<int> sk;
	while (end)
	{
		sk.push(end);
		end = preofid[end];
	}
	printf("%d", sk.top());
	sk.pop();
	while (!sk.empty())
	{
		printf(" %d", sk.top());
		sk.pop();
	}
	printf("\n");
	return 0;
}