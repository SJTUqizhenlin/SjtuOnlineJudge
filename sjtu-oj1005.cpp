#include <iostream>

using namespace std;

struct sudoku
{
	int chart[9][9];
	bool check[9];
	sudoku()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) chart[i][j] = 0;
		for (int i = 0; i < 9; i++) check[i] = false;
	}
	friend istream& operator>>(istream& cin, sudoku& sd);
	bool check_region(int xb, int yb, int xe, int ye)
	{
		if ((xe - xb + 1) * (ye - yb + 1) != 9) return false;
		for (int i = 0; i < 9; i++) check[i] = false;
		for (int i = xb; i <= xe; i++)
			for (int j = yb; j <= ye; j++)
				check[chart[i][j] - 1] = true;
		bool res = true;
		for (int i = 0; i < 9; i++) res = res && check[i];
		return res;
	}
	bool is_right()
	{
		bool res = true;
		for (int i = 0; i < 9; i++)
			res = res && check_region(i, 0, i, 8);
		for (int j = 0; j < 9; j++)
			res = res && check_region(0, j, 8, j);
		for (int i = 0; i < 9; i = i + 3)
			for (int j = 0; j < 9; j = j + 3)
				res = res && check_region(i, j, i + 2, j + 2);
		return res;
	}
};

istream& operator>>(istream& cin, sudoku& sd)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sd.chart[i][j];
	return cin;
}

int main()
{
	int T;
	cin >> T;
	sudoku s1;
	while (T--)
	{
		cin >> s1;
		bool boo = s1.is_right();
		if (boo) cout << "Right" << endl;
		else cout << "Wrong" << endl;
	}
	return 0;
}