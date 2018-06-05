#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
	int no;
	int val;
	Pair(int n, int v)
		:no(n), val(v) {}
};

bool cmp(const Pair &p1, const Pair &p2)
{
	return p1.val < p2.val;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int *arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int tmp;

	vector<Pair> v;
	bool *flag = new bool[n + 1];
	for (int i = 0; i <= n; i++)
		flag[i] = false;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &tmp);
		v.push_back(Pair(tmp, arr[tmp]));
		flag[tmp] = true;
	}
	make_heap(v.begin(), v.end(), cmp);

	bool **recog = new bool*[n + 1];
	for (int i = 0; i <= n; i++)
		recog[i] = new bool[n + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &tmp);
			recog[i][j] = tmp;
		}
	}
	int TOP;
	while (v.size())
	{
		TOP = v[0].no;
		printf("%d\n", TOP);
		pop_heap(v.begin(), v.end(), cmp);
		v.pop_back();
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i] && recog[TOP][i])
			{
				v.push_back(Pair(i, arr[i]));
				push_heap(v.begin(), v.end(), cmp);
				flag[i] = 1;
			}
		}
	}
	return 0;
}