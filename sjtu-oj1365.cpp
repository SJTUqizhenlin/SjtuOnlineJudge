#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long N, T;
	scanf("%lld%lld", &N, &T);
	vector<long long> A;
	for (int i = 0; i < N; i++) {
		long long x, v;
		scanf("%lld%lld", &x, &v);
		x = -(x + v * T);
		if (A.empty() || (-A.back()) >= (-x)) {
			A.push_back(x);
		}
		else {
			*upper_bound(A.begin(), A.end(), x) = x;
		}
	}
	printf("%d\n", A.size());
	return 0;
}