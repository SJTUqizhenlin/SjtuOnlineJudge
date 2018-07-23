#include <stdio.h>
#include <string>
using namespace std;

long long presum[1000005];

long long& readint(long long &x)
{
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x;
}

int main()
{
	long long N, M, l, r;
	readint(N); readint(M);
	for (int i = 0; i < N; ++i)
		readint(presum[i + 1]) += presum[i];
	for (int i = 0; i < M; ++i)
	{
		readint(l);
		readint(r);
		printf("%lld\n", presum[r] - presum[l - 1]);
	}
	return 0;
}