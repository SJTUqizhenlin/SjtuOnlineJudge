#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct basket
{
	int Di, Ti;
	basket() :Di(0), Ti(0) {}
};

basket bks[100005];

bool cmp1(const basket &b1, const basket &b2)
{
	return b1.Ti < b2.Ti;
}

struct cmp2
{
	bool operator()(const basket &b1, const basket &b2)
	{
		return b1.Di < b2.Di;
	}
};

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &(bks[i].Di), &(bks[i].Ti));
	sort(bks, bks + n, cmp1);
	int theend = bks[n - 1].Ti - 1;
	priority_queue<basket, vector<basket>, cmp2> pq;
	int bksid = n - 1, res = 0;
	for (theend; theend >= 0; theend--)
	{
		while (bksid >= 0 && bks[bksid].Ti > theend)
		{
			pq.push(bks[bksid]);
			bksid--;
		}
		if (!pq.empty())
		{
			res += pq.top().Di;
			pq.pop();
		}
	}
	printf("%d\n", res);
	return 0;
}