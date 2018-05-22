#include <iostream>

using namespace std;

void Print(int **root, int l, int r)
{
	cout << root[l][r] << " ";
	if (root[l][r] > l) Print(root, l, root[l][r] - 1);
	if (root[l][r] < r) Print(root, root[l][r] + 1, r);
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	long long **dp_score = new long long*[n + 2];
	for (int i = 0; i < n + 2; i++)
		dp_score[i] = new long long[n + 2];
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < n + 2; j++)
			dp_score[i][j] = 0;
	int **dp_root = new int*[n + 2];
	for (int i = 0; i < n + 2; i++)
		dp_root[i] = new int[n + 2];
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < n + 2; j++)
			dp_root[i][j] = 0;
	for (int i = 0; i < n + 1; i++)
		dp_score[i + 1][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp_score[i][i] = arr[i];
		dp_root[i][i] = i;
	}
	for (int len = 1; len < n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int j = i + len;
			long long tmp = 0;
			int mid_id = 0;
			for (int k = i; k <= j; k++)
			{
				if (dp_score[i][k - 1] * dp_score[k + 1][j] + arr[k] > tmp)
				{
					tmp = dp_score[i][k - 1] * dp_score[k + 1][j] + arr[k];
					mid_id = k;
				}
			}
			dp_score[i][j] = tmp;
			dp_root[i][j] = mid_id;
		}
	}
	cout << dp_score[1][n] << endl;
	Print(dp_root, 1, n);
	cout << endl;
	return 0;
}