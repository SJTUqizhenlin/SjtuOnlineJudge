#include <stdio.h>
using namespace std;

double arr[100005];
const double eps = 1e-7;
int n, k;

bool isOk(double x)
{
	int i = 0, j = 0, num = 0;
	while (i < n)
	{
		while (j < n && arr[j] - arr[i] < x + eps)
			++j;
		++num;
		if (num > k) return false;
		i = j;
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%lf", &arr[i]);
	double lower = 0, upper = arr[n - 1] - arr[0], mid;
	while (upper - lower > eps)
	{
		mid = (lower + upper) / 2;
		if (isOk(mid))
			upper = mid;
		else
			lower = mid;
	}
	upper = upper / 2;
	printf("%.6f\n", upper);
	return 0;
}