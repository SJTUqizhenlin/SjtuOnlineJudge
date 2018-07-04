#include <iostream>
using namespace std;

char g[60][60][60];
long long numof[256];

int main()
{
	int n, m; cin >> n >> m;
	int minmn = (m < n ? m : n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> g[i][j][0];
	for (int k = 1; k < minmn; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				g[i][j][k] = g[i][j][k - 1];
				if (i >= k && j >= k && g[i - k][j - k][0] != '.')
					g[i][j][k] = '.';
			}
	int T; cin >> T;
	if (T <= minmn)
	{
		for (int t = 0; t < T; t++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					numof[g[i][j][t]]++;
	}
	else
	{
		for (int t = 0; t < minmn; t++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					numof[g[i][j][t]]++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				numof[g[i][j][minmn - 1]] += (T - minmn);
	}
	cout << numof['R'] << " " << numof['G'] << " " << numof['B'] << endl;
	return 0;
}