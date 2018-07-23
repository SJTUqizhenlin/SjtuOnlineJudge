#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

LL arr[300010];
LL pow2[300010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	pow2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		pow2[i] = pow2[i - 1] * 2;
		pow2[i] %= MOD;
	}
	sort(arr + 1, arr + n + 1);
	LL res = 0, tmp = 0;
	for (int i = 1; i < n; i++)
	{
		tmp = pow2[i] - 1;
		tmp *= (pow2[n - i] - 1);
		tmp %= MOD;
		tmp *= (arr[i + 1] - arr[i]);
		tmp %= MOD;
		res += tmp;
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}