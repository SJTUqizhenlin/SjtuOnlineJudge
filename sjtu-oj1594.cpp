#include <iostream>
using namespace std;
const int maxn = 10010000;
typedef long long LL;

LL arr[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	int nline = m + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i * nline + j];
			arr[i * nline + j] += arr[(i - 1) * nline + j];
			arr[i * nline + j] += arr[i * nline + j - 1];
			arr[i * nline + j] -= arr[(i - 1) * nline + j - 1];
		}
	int x1, y1, x2, y2;
	LL res;
	for (int i = 0; i < q; i++)
	{
		res = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		res += arr[x2 * nline + y2];
		res -= arr[(x1 - 1) * nline + y2];
		res -= arr[x2 * nline + y1 - 1];
		res += arr[(x1 - 1) * nline + y1 - 1];
		cout << res << '\n';
	}
	return 0;
}