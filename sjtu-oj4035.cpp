#include <stdio.h>
#define max(a, b) ((a) > (b) ? a : b)
using namespace std;
typedef long long LL;

LL arr[500010];
LL n, m;

bool isOk(LL x)
{
	LL tmp, sum = 0;
	for (LL i = 0; i < n; i++)
	{
		tmp = (arr[i] / x) + (arr[i] % x == 0 ? 0 : 1);
		sum += tmp;
		if (sum > m) return false;
	}
	return true;
}

LL binFind(LL l, LL r)
{
	if (r - l <= 1) return r;
	LL mid = (l + r) / 2;
	if (isOk(mid)) return binFind(l, mid);
	else return binFind(mid, r);
}

int main()
{
	scanf("%lld%lld", &n, &m);
	LL maxval = 0;
	for (LL i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
		maxval = max(arr[i], maxval);
	}
	LL res = binFind(0, maxval);
	printf("%lld\n", res);
	return 0;
}