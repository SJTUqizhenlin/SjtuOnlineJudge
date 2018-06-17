#include <stdio.h>
using namespace std;

long long arr[100005];
long long presum[100005];
int N, F;

void init()
{
	scanf("%d%d", &N, &F);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &(arr[i]));
		presum[i] = presum[i - 1] + arr[i];
	}
	return;
}

int main()
{
	init();
	int i, j;
	double res = -1;
	for (j = 0, i = 0; i + F <= N; i++)
	{
		if (i > j && ((presum[i] - presum[j]) * (i + F - j) <
			(presum[i + F] - presum[j]) * (i - j)))
			j = i;
		if (res * (i - j + F) < presum[i + F] - presum[j])
			res = (double)(presum[i + F] - presum[j]) / (i - j + F);
	}
	printf("%d\n", (int)(1000 * res));
	return 0;
}