#include <stdio.h>
using namespace std;

int arr[100010];
int bitr[100010];
int N;

void add_at(int i)
{
	while (i <= 100000) {
		bitr[i]++;
		i += (i & (-i));
	} return;
}

int sum_at(int i)
{
	int res = 0;
	while (i > 0) {
		res += bitr[i];
		i -= (i & (-i));
	} return res;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &(arr[i]));
	long long res = 0;
	for (int i = 1; i <= N; i++) {
		add_at(arr[i]);
		res += (i - sum_at(arr[i]));
	}
	printf("%lld\n", res);
	return 0;
}