// OK, this is just a test for github&git
#include <iostream>

using namespace std;

int main()
{
	int l, w;
	cin >> l >> w;
	int **arr = new int *[l];
	for (int i = 0; i < l; i++)
	{
		arr[i] = new int[w];
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
			arr[i][j] += (i >= 1 ? arr[i - 1][j] : 0);
			arr[i][j] += (j >= 1 ? arr[i][j - 1] : 0);
			arr[i][j] -= ((i > 0 && j > 0) ? arr[i - 1][j - 1] : 0);
		}
	}
	int a, b;
	int max = 0;
	int tmp = 0;
	cin >> a >> b;
	for (int i = a - 1; i < l; i++)
	{
		for (int j = b - 1; j < w; j++)
		{
			tmp = arr[i][j];
			tmp -= (i > a - 1 ? arr[i - a][j] : 0);
			tmp -= (j > b - 1 ? arr[i][j - b] : 0);
			tmp += ((i >= a && j >= b) ? arr[i - a][j - b] : 0);
			if (tmp > max) max = tmp;
		}
	}
	cout << max;
	return 0;
}