#include <stdio.h>
#include <unordered_map>

using namespace std;

const int maxn = 100005;
int cowarr[maxn];
int n, k;

struct grp
{
	int no, num;
	grp() :no(0), num(0) {}
	grp(int noval) :no(noval), num(1) {}
};

grp pq[maxn];
unordered_map<int, int> idmap;

void Exchange(int a, int b)
{
	grp tmp = pq[a];
	pq[a] = pq[b];
	pq[b] = tmp;
	idmap[pq[a].no] = a;
	idmap[pq[b].no] = b;
}

void upchange(int x)
{
	while (x > 1)
	{
		if (pq[x >> 1].num < pq[x].num)
		{
			Exchange(x, x >> 1);
			x = x >> 1;
		}
		else break;
	}
	return;
}

void downchange(int x, int pqsize)
{
	int maxi = x;
	while (x << 1 <= pqsize)
	{
		if (pq[x << 1].num > pq[maxi].num) maxi = x << 1;
		if (x << 1 <= pqsize - 1)
			if (pq[(x << 1) + 1].num > pq[maxi].num) maxi = (x << 1) + 1;
		if (maxi == x) break;
		else { Exchange(x, maxi); x = maxi; }
	}
	return;
}

void pq_push(grp newgrp, int pqsize)
{
	pq[pqsize] = newgrp;
	idmap[newgrp.no] = pqsize;
	upchange(pqsize);
}

void pq_erase(int pos, int pqsize)
{
	pq[pos] = pq[pqsize];
	idmap[pq[pos].no] = pqsize;
	idmap[pq[pqsize].no] = pos;
	downchange(pos, pqsize - 1);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &cowarr[i]);
	int pqsize = 0;
	int ed = 0, beg = 0, res = 0;
	while (ed < n)
	{
		if (pqsize == k + 1)
		{
			while (pq[idmap[cowarr[beg]]].num > 1)
			{
				pq[idmap[cowarr[beg]]].num -= 1;
				downchange(idmap[cowarr[beg]], pqsize);
				beg++;
			}
			pq_erase(idmap[cowarr[beg]], pqsize);
			idmap.erase(cowarr[beg]);
			pqsize -= 1;
			beg++;
		}
		while (ed < n && idmap.find(cowarr[ed]) != idmap.end())
		{
			pq[idmap[cowarr[ed]]].num++;
			upchange(idmap[cowarr[ed]]);
			ed++;
		}
		if (ed < n)
		{
			grp* newgrp = new grp(cowarr[ed]);
			pq_push(*newgrp, pqsize + 1);
			pqsize++;
			ed++;
		}
		while (ed < n && idmap.find(cowarr[ed]) != idmap.end())
		{
			pq[idmap[cowarr[ed]]].num++;
			upchange(idmap[cowarr[ed]]);
			ed++;
		}
		if (res < pq[1].num) res = pq[1].num;
	}
	printf("%d\n", res);
	return 0;
}