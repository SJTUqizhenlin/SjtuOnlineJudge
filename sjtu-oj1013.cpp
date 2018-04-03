#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int v, n;
	cin >> v >> n;
	int **arr = new int *[2];
	arr[0] = new int[v + 1];
	arr[1] = new int[v + 1];
	for (int i = 0; i <= v; i++)
	{
		arr[0][i] = 0;
		arr[1][i] = 0;
	}
	int cur = 1;
	int c, w;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> w;
		for (int j = 1; j <= v; j++)
		{
			arr[cur][j] = max(arr[1 - cur][j], (j >= c ? (arr[cur][j - c] + w) : arr[1 - cur][j]));
		}
		cur = 1 - cur;
	}
	int res = 0;
	for (int i = 1; i <= v; i++)
		if (arr[1 - cur][i] > res) res = arr[1 - cur][i];
	cout << res;
	return 0;
}