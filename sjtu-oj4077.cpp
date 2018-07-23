#include <stdio.h>
#include <algorithm>
using namespace std;

const double log23 = 1.5849625;
struct num {
	int p2, p3;
	num() :p2(0), p3(0) {}
};
num arr[50005];
int n;
bool cmp(const num &n1, const num &n2) {
	return ((n1.p2 + log23 * n1.p3) < (n2.p2 + log23 * n2.p3));
}

int main()
{
	scanf("%d", &n);
	int max2 = 0, max3 = 0, min2 = 1001, min3 = 1001;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &(arr[i].p2), &(arr[i].p3));
		if (arr[i].p2 > max2) max2 = arr[i].p2;
		if (arr[i].p2 < min2) min2 = arr[i].p2;
		if (arr[i].p3 > max3) max3 = arr[i].p3;
		if (arr[i].p3 < min3) min3 = arr[i].p3;
	}
	sort(arr + 1, arr + n + 1, cmp);
	int res1, res2, res3, res4;
	if (n == 1)
		printf("%d %d %d %d\n", arr[1].p2, arr[1].p3, arr[1].p2, arr[1].p3);
	else
	{
		if (n == 2)
		{
			printf("%d %d %d %d\n", max2, max3, max2, max3);
			printf("%d %d %d %d\n", min2, min3, min2, min3);
		}
		else
		{
			printf("%d %d %d %d\n", max2, max3, max2, max3);
			for (int k = 1; k < n - 1; k++)
			{
				if (k == n - 2) {
					res1 = arr[n].p2;
					res2 = arr[n].p3;
				}
				else {
					res1 = max2;
					res2 = max3;
				}
				if (k == 1) {
					res3 = arr[1].p2;
					res4 = arr[1].p3;
				}
				else {
					res3 = min2;
					res4 = min3;
				}
				printf("%d %d %d %d\n", res1, res2, res3, res4);
			}
			printf("%d %d %d %d\n", min2, min3, min2, min3);
		}
	}
	return 0;
}