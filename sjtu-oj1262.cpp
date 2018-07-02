#include <stdio.h>
#include <algorithm>

using namespace std;

struct timenode
{
	int val;
	bool BorE;
	timenode() : val(0), BorE(false) {}
};

bool cmp(const timenode &t1, const timenode &t2)
{
	if (t1.val != t2.val)
		return t1.val < t2.val;
	return (t1.BorE && !t2.BorE);
}

int main()
{
	int n;
	scanf("%d", &n);
	timenode* arr = new timenode[n * 2];
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		arr[i * 2].val = a;
		arr[i * 2].BorE = true;
		arr[i * 2 + 1].val = b;
	}
	sort(arr, arr + n * 2, cmp);
	int bg = -1, ed = -1;
	int bgcount = 0;
	int maxin = 0;
	int maxout = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (arr[i].BorE)
		{
			if (bgcount == 0 && ed != -1)
				if (arr[i].val - ed > maxout) maxout = arr[i].val - ed;
			bgcount++;
			if (bgcount == 1) bg = arr[i].val;
		}
		else
		{
			bgcount--;
			if (bgcount == 0)
			{
				if (arr[i].val - bg > maxin) maxin = arr[i].val - bg;
				ed = arr[i].val;
			}
		}
	}
	printf("%d %d\n", maxin, maxout);
	return 0;
}