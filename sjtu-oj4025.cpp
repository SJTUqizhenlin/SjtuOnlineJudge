#include <stdio.h>
using namespace std;
typedef long long LL;

LL MapArr[505][505], V;
int M, N;
inline double absof(double x) { return (x > 0 ? x : (-x)); }

int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) scanf("%lld", &MapArr[i][j]);
	scanf("%lld", &V);
	double l = 0, r = 1e12, mid;
	double vsum;
	while (r - l > 1e-6)
	{
		vsum = 0;
		mid = (l + r) / 2;
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
			{
				if (MapArr[i][j] < mid) vsum += (mid - MapArr[i][j]);
				if (vsum > V + 5e-1) break;
			}
		if (vsum > V) r = mid;
		else l = mid;
	}
	printf("%.2f\n", mid);
	double area = 0;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			if (MapArr[i][j] < mid - 1e-5) area += 100;
	printf("%.2f\n", (area / (M * N)));
	return 0;
}