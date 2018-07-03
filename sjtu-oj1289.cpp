#include <stdio.h>
#include <algorithm>
using namespace std;
int nums[100005];
int presum[100005];
int uqsum[100005];
int cnt = 0;
int c[100005];
const int MOD = 1000000009;

inline int lowbit(int cid) {
	return (cid & (-cid));
}

int getSum(int cid) {
	int sum = 0;
	for (int i = cid; i >= 1; i -= lowbit(i))
		sum = (sum + c[i]) % MOD;
	return sum;
}

void update(int cid, int value) {
	for (int i = cid; i <= cnt; i += lowbit(i))
		c[i] = (c[i] + value) % MOD;
	return;
}

inline int find(int key) { 
	return lower_bound(uqsum, uqsum + cnt, key) - uqsum; 
}

int main() {
	int N; scanf("%d", &N);
	presum[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &(nums[i]));
		presum[i] = presum[i - 1] + nums[i];
	}
	sort(presum, presum + N + 1);
	uqsum[cnt] = presum[0];
	for (int i = 1; i < N + 1; ++i)
		if (presum[i] != uqsum[cnt])
			uqsum[++cnt] = presum[i];
	cnt++;
	update(find(0) + 1, 1);
	int res = 0; 
	int curSum = 0;
	int cid = 0;
	for (int i = 1; i <= N; ++i){
		curSum += nums[i];
		cid = find(curSum) + 1; 
		res = getSum(cid); 
		update(cid, res); 
	}
	printf("%d\n", res);
	return 0;
}