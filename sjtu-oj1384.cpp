//There is a wrong statament in this problem,
//which is, the answer should MOD 1000000007(1e9 + 7);


#include <stdio.h>
using namespace std;
typedef long long LL;

const int MAXN = (1 << 20);
const int MOD = 1000000007;
int arr[MAXN]; int N;

LL Pow2(int a) {
	if (a == 0) return 1;
	LL h = Pow2(a / 2);
	if (a % 2 == 0) return (h * h) % MOD;
	return (h * h * 2) % MOD;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &(arr[i]));
	int tar = 3; LL res = 0;
	for (int i = N; i > 0; i--) {
		if (arr[i] != tar) {
			res += Pow2(i - 1);
			res %= MOD;
			tar = 6 - tar - arr[i];
		}
	}
	printf("%lld\n", res);
	return 0;
}