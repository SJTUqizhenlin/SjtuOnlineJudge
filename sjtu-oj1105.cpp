#include <string>
#include <iostream>
using namespace std;

const int INF = (1 << 30);

struct road
{
	//int beg, end, len, peo, lig;
	int val[5];
	road() { for (int i = 0; i < 5; i++) val[i] = 0; }
};
road roads[10005];

struct Gnode
{
	int w, no; Gnode* next;
	Gnode() :w(0), no(0), next(nullptr) {}
	Gnode(int ww, int nno) :w(ww), no(nno), next(nullptr) {}
};
Gnode G[1005];

void extract5num(char *s, int len, int i)
{
	int tmp = 0, pos = 0, gets = 0;
	while (pos < len)
	{
		if (*s < '0' || *s > '9') { s++; pos++; }
		else
		{
			while (*s >= '0' && *s <= '9' && pos < len)
			{
				tmp = tmp * 10 + *s - '0';
				s++; pos++;
			}
			roads[i].val[gets] = tmp;
			tmp = 0; gets++;
		}
	}
	return;
}

void init_G(int i, int m, int n)
{
	for (int j = 1; j <= n; j++) G[j].next = nullptr; //no memery recovery
	for (int j = 0; j < m; j++)
	{
		Gnode *tmp = new Gnode(roads[j].val[i], roads[j].val[1]);
		tmp->next = G[roads[j].val[0]].next;
		G[roads[j].val[0]].next = tmp;
		Gnode *tmp2 = new Gnode(roads[j].val[i], roads[j].val[0]);
		tmp2->next = G[roads[j].val[1]].next;
		G[roads[j].val[1]].next = tmp2;
	}
	return;
}

int pq[1005], posof[1005], flag[1005], dis[1005];
int pqlen;

void exchange(int p1, int p2)
{
	int tmp = pq[p1]; pq[p1] = pq[p2]; pq[p2] = tmp;
	posof[pq[p1]] = p1;
	posof[pq[p2]] = p2;
}

void relax(int u, int v, int w)
{
	if (dis[u] + w < dis[v])
	{
		dis[v] = dis[u] + w;
		int pv = posof[v];
		while (pv > 1)
		{
			if (dis[pq[pv]] < dis[pq[pv / 2]]) { exchange(pv, pv / 2); pv = pv / 2; }
			else break;
		}
	}
	return;
}

void pqpop()
{
	exchange(1, pqlen); 
	int pos = 1; pqlen--;
	int np;
	while (pos * 2 <= pqlen)
	{
		if (pos * 2 + 1 <= pqlen)
			np = (dis[pq[pos * 2 + 1]] > dis[pq[pos * 2]] ? pos * 2 : pos * 2 + 1);
		else
			np = pos * 2;
		if (dis[pq[pos]] > dis[pq[np]]) { exchange(pos, np); pos = np; }
		else break;
	}
	return;
}

int findMinPath(int s, int t, int n)
{
	for (int i = 1; i <= n; i++) 
	{ 
		pq[i] = i; posof[i] = i; 
		flag[i] = 0; dis[i] = INF; 
	}
	pqlen = n; dis[s] = 0; exchange(s, 1); flag[s] = 1;
	while (!flag[t])
	{
		int pqtop = pq[1];
		pqpop();
		Gnode *cur = G[pqtop].next;
		while (cur)
		{
			if (!flag[cur->no])
				relax(pqtop, cur->no, cur->w);
			cur = cur->next;
		}
		flag[pq[1]] = 1;
	}
	return dis[t];
}

int main()
{
	int T; 
	cin >> T;
	string sent;
	int n, m, s, t;
	while (T--)
	{
		cin >> n >> m >> s >> t;
		getline(cin, sent);
		for (int i = 0; i < m; i++)
		{
			getline(cin, sent);
			extract5num(&sent[0], sent.length(), i);
		}
		for (int i = 2; i < 5; i++)
		{
			init_G(i, m, n);
			int res = findMinPath(s, t, n);
			cout << res << " ";
		}
		cout << endl;
	}
	return 0;
}