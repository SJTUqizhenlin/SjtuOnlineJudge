#include <iostream>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define squa(x) ((x) * (x))
typedef long long LL;
using namespace std;

LL findLen(LL x, LL y, LL N)
{
	LL loop = min(min(N - x, x - 1), min(N - y, y - 1));
	LL res = squa(N) - squa(N - loop * 2);
	if (y == 1 + loop)
	{
		res += (N - loop + 1 - x);
		return (res - 1);
	}
	if (x == 1 + loop)
	{
		res += (N - loop * 2 + y - 1 - loop);
		return (res - 1);
	}
	if (y == N - loop)
	{
		res += (N * 2 - loop * 4 - 2 + x - loop);
		return (res - 1);
	}
	else
	{
		res += (N * 3 - loop * 6 - 3 + N - loop + 1 - y);
		return (res - 1);
	}
}

int main()
{
	LL N, i0, j0;
	cin >> N >> i0 >> j0;
	LL res1 = findLen(i0, j0, N);
	LL res2 = findLen(N + 1 - i0, N + 1 - j0, N);
	cout << res1 << " " << res2 << endl;
	return 0;
}