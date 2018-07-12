#include <iostream>

using namespace std;

int arr[1005][1005];

void fillin(int &x, int &y, int space, int &val, int dir)
{
	if (dir == 0)
	{
		for (int i = 0; i < space; i++)
		{
			y++;
			val++;
			arr[x][y] = val;
		}
	}
	if (dir == 1)
	{
		for (int i = 0; i < space; i++)
		{
			x++;
			val++;
			arr[x][y] = val;
		}
	}
	if (dir == 2)
	{
		for (int i = 0; i < space; i++)
		{
			y--;
			val++;
			arr[x][y] = val;
		}
	}
	if (dir == 3)
	{
		for (int i = 0; i < space; i++)
		{
			x--;
			val++;
			arr[x][y] = val;
		}
	}
	return;
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	int ox = 1;
	int oy = 0;
	int val = -1;
	int dir = 0;
	fillin(ox, oy, n, val, dir);
	for (int space = n - 1; space > 0; space--)
	{
		dir++;
		dir %= 4;
		fillin(ox, oy, space, val, dir);
		dir++;
		dir %= 4;
		fillin(ox, oy, space, val, dir);
	}
	cout << arr[x][y] << endl;

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//		cout << arr[i][j] << " ";
	//	cout << endl;
	//}
	return 0;
}