#include <stdio.h>
using namespace std;

int marks[100000];
int presum[100000];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int mark = 0;
		scanf("%d", &mark);
		++marks[mark];
	}
	presum[0] = 0;
	for (int i = 1; i < 100000; ++i)
		presum[i] = presum[i - 1] + marks[i];
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", presum[b] - presum[a - 1]);
	}
	return 0;
}