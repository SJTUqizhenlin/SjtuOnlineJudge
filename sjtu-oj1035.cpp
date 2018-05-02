#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	int no;
	int val;
	node(int n, int v)
		:no(n), val(v) {}
	node()
		:no(0), val(0) {}
	bool operator<(const node a) const
	{
		if (a.val == val) return no > a.no;
		return a.val > val;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	vector<node> v(n + 1);
	int *idof = new int[n + 1];
	int vi;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &vi);
		v[i].no = i;
		v[i].val = vi;
		idof[i] = i;
	}
	int k;
	scanf("%d", &k);
	char order;
	int x, y;
	for (int i = 0; i < k; i++)
	{
		scanf("\n%c", &order);
		if (order == 'M')
		{
			scanf("%d%d", &x, &y);
			v[idof[x]].val = y;
		}
		if (order == 'Q')
		{
			make_heap(v.begin() + 1, v.end());
			scanf("%d", &x);
			int bound = 0;
			for (int j = 0; j < x; j++)
			{
				scanf("%d", &y);
				while (y > bound)
				{
					pop_heap(v.begin() + 1, v.end() - bound);
					bound++;
				}
				printf("%d ", v[n + 1 - y].no);
			}
			printf("\n");
			for (int j = 1; j <= n; j++)
				idof[v[j].no] = j;
		}
	}
	return 0;
}