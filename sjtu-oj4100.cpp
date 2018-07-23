#include <stdio.h>
using namespace std;

int bitr[1000010];
int n;
int arr[1000010];
int inv[1000010];

void add_on(int id, int num)
{
	while (id <= n)
	{
		bitr[id] += num;
		id += (id & (-id));
	}
	return;
}

void init()
{
	for (int i = 0; i <= n; i++)
		bitr[i] = 0;
	for (int i = 1; i <= n; i++)
		add_on(i, 1);
	return;
}

int sum_of(int id)
{
	int res = 0;
	while (id)
	{
		res += bitr[id];
		id -= (id & (-id));
	}
	return res;
}

int find_kth(int k)
{
	int l = 0, r = n, mid;
	while (r > l + 1)
	{
		mid = (l + r) / 2;
		if (sum_of(mid) < k) l = mid;
		else r = mid;
	}
	return r;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", &inv[i]);
		int k;
		for (int i = n; i >= 1; i--)
		{
			k = i - (inv[i] - inv[i - 1]);
			arr[i] = find_kth(k);
			add_on(arr[i], -1);
		}
		printf("1\n");
		for (int i = 1; i <= n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}