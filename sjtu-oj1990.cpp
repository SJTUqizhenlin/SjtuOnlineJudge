#include <stdio.h>

using namespace std;

const int maxn = 2000000;
int cdarr[maxn + 5];
int posofid[maxn + 5];
int idofpos[maxn + 5];
int timeof[maxn + 5];
int Time = 0;

void Exchange(int a, int b)
{
	int tmp = cdarr[a];
	cdarr[a] = cdarr[b];
	cdarr[b] = tmp;
	tmp = idofpos[a];
	idofpos[a] = idofpos[b];
	idofpos[b] = tmp;
	posofid[idofpos[a]] = a;
	posofid[idofpos[b]] = b;
}

bool lessthan(int a, int b)
{
	if (cdarr[a] < cdarr[b]) return true;
	if (cdarr[a] == cdarr[b]) return timeof[idofpos[a]] > timeof[idofpos[b]];
	return false;
}

void MakeHeap(int n)
{
	int curid, minid;
	for (int i = n / 2; i >= 1; i--)
	{
		curid = i;
		while (curid << 1 <= n)
		{
			minid = curid;
			if (lessthan(curid << 1, minid)) minid = curid << 1;
			if ((curid << 1) + 1 <= n)
				if (lessthan((curid << 1) + 1, minid)) minid = (curid << 1) + 1;
			if (curid == minid) break;
			else
			{
				Exchange(curid, minid);
				curid = minid;
			}
		}
	}
}

void HeapInc(int x, int n)
{
	cdarr[x] += 1;
	int cur = x, mini;
	while (cur << 1 <= n)
	{
		mini = cur;
		if (lessthan(cur << 1, mini)) mini = cur << 1;
		if ((cur << 1) + 1 <= n)
			if (lessthan((cur << 1) + 1, mini)) mini = (cur << 1) + 1;
		if (cur == mini) break;
		else
		{
			Exchange(cur, mini);
			cur = mini;
		}
	}
}

void HeapDec(int x)
{
	cdarr[x] -= 1;
	while (x > 1)
	{
		if (lessthan(x, x >> 1))
		{
			Exchange(x, x >> 1);
			x = x >> 1;
		}
		else break;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cdarr[i]);
		idofpos[i] = i;
		posofid[i] = i;
		timeof[i] = ++Time;
	}
	MakeHeap(n);
	int x, y;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		if (y == 1) { timeof[x] = ++Time;  HeapInc(posofid[x], n); }
		else { timeof[x] = ++Time; HeapDec(posofid[x]); }
		printf("%d\n", idofpos[1]);
	}
	return 0;
}