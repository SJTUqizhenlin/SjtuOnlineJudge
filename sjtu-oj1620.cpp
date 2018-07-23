#include <stdio.h>
#include <stdint.h>

using namespace std;

const long long MOD = 1000000007;
long long arr[60005];
long long segtr[30][60005];
long long powerof2[30];
long long N, Q;

void init_powerof2()
{
	powerof2[0] = 1;
	for (int i = 1; i < 30; i++) powerof2[i] = powerof2[i - 1] << 1;
	return;
}

int lowbit(int x)
{
	return x & (-x);
}

void segtr_add(int id, int bitno, int num)
{
	while (id <= N)
	{
		segtr[bitno][id] += num;
		id += lowbit(id);
	}
}

long long segtr_sum(int id, int bitno)
{
	long long res = 0;
	while (id > 0)
	{
		res += segtr[bitno][id];
		id -= lowbit(id);
	}
	return res;
}

int main()
{
	init_powerof2();
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);
		for (int j = 0; j < 30; j++)
			if (arr[i] & powerof2[j]) segtr_add(i, j, 1);
	}
	scanf("%lld", &Q);
	int cm, ar1, ar2;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d%d%d", &cm, &ar1, &ar2);
		if (cm == 1)
		{
			for (int j = 0; j < 30; j++)
				if (arr[ar1] & powerof2[j]) segtr_add(ar1, j, -1);
			arr[ar1] = ar2;
			for (int j = 0; j < 30; j++)
				if (arr[ar1] & powerof2[j]) segtr_add(ar1, j, 1);
		}
		else
		{
			long long res = 0;
			long long onenum = 0;
			for (int j = 0; j < 30; j++)
			{
				onenum = segtr_sum(ar2, j) - segtr_sum(ar1 - 1, j);
				res += (ar2 - ar1 + 1 - onenum) * onenum * powerof2[j];
				res %= MOD;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}