#include <iostream>
#include <iomanip>

using namespace std;

void fillin(int arr[150][150], int point, int size, int &beg)
{
	for (int i = 0; i < size; i++)
	{
		arr[point][point + i] = beg;
		beg++;
	}
	for (int i = 1; i < size; i++)
	{
		arr[point + i][point + size - 1] = beg;
		beg++;
	}
	for (int i = 1; i < size; i++)
	{
		arr[point + size - 1][point + size - i - 1] = beg;
		beg++;
	}
	for (int i = 1; i < size - 1; i++)
	{
		arr[point + size - i - 1][point] = beg;
		beg++;
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	int arr[150][150];
	int beg = 1;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		fillin(arr, i, n - i * 2, beg);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(6) << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}