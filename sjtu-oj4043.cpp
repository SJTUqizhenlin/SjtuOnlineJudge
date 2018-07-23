#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[5010];
int n, m, x, y, a, b, c, o;
inline bool gr(int num) { return num > a; }
bool cmp(int p, int q) {
	int p1 = a * p * p + b * p + c;
	int q1 = a * q * q + b * q + c;
	return (p1 > 0 && q1 <= 0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) sort(arr + x, arr + y);
		if (o == 2) reverse(arr + x, arr + y);
		if (o == 3)
		{
			for (int i = x; i < y; i++)
				printf("%d ", arr[i]);
			printf("\n");
		}
		if (o == 4) printf("%d\n", *(min_element(arr + x, arr + y)));
		if (o == 5) {
			scanf("%d", &a);
			printf("%d\n", count_if(arr + x, arr + y, gr));
		}
		if (o == 6) {
			scanf("%d", &a);
			printf("%d\n", find(arr + x, arr + y, a) - arr);
		}
		if (o == 7) {
			scanf("%d%d", &a, &b);
			replace(arr + x, arr + y, a, b);
		}
		if (o == 8) {
			scanf("%d%d%d", &a, &b, &c);
			stable_sort(arr + x, arr + y, cmp);
		}
	}
	return 0;
}