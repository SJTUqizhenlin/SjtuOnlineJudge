#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[16][16];
const int INF = 1000000;
int f[1 << 16][16];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	if (n == 1)
		cout << 2 * map[0][0] << endl;
	else
	{
		for (int i = 0; i < (1 << (n - 1)); i++)
		{
			for (int j = 1; j < n; j++) 
			{
				if (i == (1 << (j - 1)))
					f[i][j] = map[0][j];
				else 
				{
					if (i & (1 << (j - 1)))
					{
						f[i][j] = INF;
						for (int k = 1; k < n; k++)
							if (k != j && (i & (1 << (k - 1))))
								f[i][j] = min(f[i ^ (1 << (j - 1))][k] + map[k][j], f[i][j]);
					}
				}
			}
		}

		int res = INF;
		for (int i = 1; i < n; ++i)
		{
			res = min(res, f[(1 << (n - 1)) - 1][i] + map[i][0]);
		}
		cout << res << endl;
	}
	return 0;
}