#include <stdio.h>
#include <algorithm>
using namespace std;

struct leg
{
	int length, timecost;
	int timerank;
	leg()
	{
		length = timecost = 0;
		timerank = 0;
	}
};

leg legarr[100005];
int n, totaltime;

bool cmp1(leg &l1, leg &l2)
{
	return l1.timecost > l2.timecost;
}

bool cmp2(leg &l1, leg &l2)
{
	return l1.length < l2.length;
}

int bit_countsum[100005];
int bit_timesum[100005];

void add_on(int *arr, int id, int x)
{
	while (id <= n)
	{
		arr[id] += x;
		id += (id & (-id));
	}
	return;
}

int sum_on(int *arr, int id)
{
	int res = 0;
	while (id)
	{
		res += arr[id];
		id -= (id & (-id));
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &(legarr[i].length));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &(legarr[i].timecost));
		totaltime += legarr[i].timecost;
	}
	sort(legarr + 1, legarr + n + 1, cmp1);
	for (int i = 1; i <= n; i++)
		legarr[i].timerank = i;
	sort(legarr + 1, legarr + n + 1, cmp2);
	int beg = 1, end = 0;
	int step = 0;
	int sum1 = 0;
	int res = totaltime, tmpres = 0;
	int lid, rid, mid;
	while (beg <= n)
	{
		sum1 = 0;
		while (end + 1 <= n && legarr[end + 1].length == legarr[beg].length)
		{
			end++;
			sum1 += legarr[end].timecost;
		}
		step = end - beg + 1;
		if (step > beg - 1)
		{
			tmpres = totaltime - sum1;
			tmpres -= sum_on(&bit_timesum[0], n);
			if (tmpres < res) res = tmpres;
		}
		else
		{
			tmpres = totaltime - sum1;
			lid = 0, rid = n;
			while (rid - lid > 1)
			{
				mid = (lid + rid) / 2;
				if (sum_on(&bit_countsum[0], mid) < step)
					lid = mid;
				else
					rid = mid;
			}
			tmpres -= sum_on(&bit_timesum[0], lid);
			if (tmpres < res) res = tmpres;
		}
		for (int i = beg; i <= end; i++)
		{
			add_on(&bit_countsum[0], legarr[i].timerank, 1);
			add_on(&bit_timesum[0], legarr[i].timerank, legarr[i].timecost);
		}
		beg = end + 1;
	}
	printf("%d\n", res);
	return 0;
}