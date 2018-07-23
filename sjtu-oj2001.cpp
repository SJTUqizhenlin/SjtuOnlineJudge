#include <stdio.h>
using namespace std;

int arr[10005];
int N, M;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &(arr[i])); arr[i] += arr[i - 1];
	}
	scanf("%d", &M); int l, r;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", (arr[r] - arr[l - 1]));
	}
	return 0;
}