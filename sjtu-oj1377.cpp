#include <stdio.h>

using namespace std;

const int maxn = 100000;
int recdleft[maxn * 2];
int recdright[maxn * 2];
int arr[maxn];

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	int begpos = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] == b) begpos = i;
	}
	recdleft[maxn] = recdright[maxn] = 1;
	int status = 0;
	for (int i = begpos + 1; i < n; i++)
		if (arr[i] > arr[begpos])
		{
			status++;
			recdright[maxn + status]++;
		}
		else
		{
			status--;
			recdright[maxn + status]++;
		}
	status = 0;
	for (int i = begpos - 1; i >= 0; i--)
		if (arr[i] > arr[begpos])
		{
			status++;
			recdleft[maxn + status]++;
		}
		else
		{
			status--;
			recdleft[maxn + status]++;
		}
	long long res = 0;
	for (int i = 1; i < maxn * 2; i++)
	{
		if (recdleft[i] > 0 && recdright[maxn * 2 - i] > 0)
		{
			res += ((long long)recdleft[i] * (long long)recdright[maxn * 2 - i]);
		}
	}
	printf("%lld\n", res);
	return 0;
}