#include <iostream>
#include <stdio.h>

using namespace std;

int maparr[500][500];
int resarr[500][500];
int flagarr[500][500];
int R, C;

int endwith(int r, int c)
{
	if (flagarr[r][c] == 1) return resarr[r][c];
	if (r > 0)
		if (maparr[r - 1][c] > maparr[r][c])
		{
			int up = endwith(r - 1, c);
			if (up >= resarr[r][c]) resarr[r][c] = up + 1;
		}
	if (c > 0)
		if (maparr[r][c - 1] > maparr[r][c])
		{
			int left = endwith(r, c - 1);
			if (left >= resarr[r][c]) resarr[r][c] = left + 1;
		}
	if (r < R - 1)
		if (maparr[r + 1][c] > maparr[r][c])
		{
			int down = endwith(r + 1, c);
			if (down >= resarr[r][c]) resarr[r][c] = down + 1;
		}
	if (c < C - 1)
		if (maparr[r][c + 1] > maparr[r][c])
		{
			int right = endwith(r, c + 1);
			if (right >= resarr[r][c]) resarr[r][c] = right + 1;
		}
	flagarr[r][c] = 1;
	return resarr[r][c];
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &maparr[i][j]);
			resarr[i][j] = 1;
		}
	int tmp = 0, res = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			tmp = endwith(i, j);
			if (tmp > res) res = tmp;
		}
	cout << res << endl;
	return 0;
}