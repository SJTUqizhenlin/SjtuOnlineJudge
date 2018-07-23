#include <stdio.h>
#include <algorithm>
using namespace std;
#define max(a, b) (a > b ? a : b);

int sum1[1005];
int sum2[1005];
char matarr[1005][1005];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", &matarr[i]);
	int res_num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
			sum2[j] = sum1[j] = (matarr[j][i] == '1' ? sum1[j] + 1 : 0);
		sort(sum2, sum2 + n);
		for (int j = 0; j < n; j++)
			res_num = max(res_num, sum2[j] * (n - j));
	}
	printf("%d\n", res_num);
	return 0;
}