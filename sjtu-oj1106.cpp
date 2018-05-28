#include <iostream>
#include <vector>

using namespace std;

class sudoku
{
private:
	int chart[9][9];
	int count_sol;
	bool possibchart[9][9][9];
	int possibnum[9][9];
	bool init_possibchart();
	bool write_in(int ix, int iy, int num);
	int getminpossibind();
	void solve_try();
	bool already_solved();
	//void print_chart();
public:
	sudoku();
	friend istream& operator>>(istream& cin, sudoku& sd);
	void solve_self();
	bool isLegal();
};

//void sudoku::print_chart()
//{
//	cout << endl;
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//			cout << chart[i][j] << " ";
//		cout << endl;
//	}
//	return;
//}

bool sudoku::isLegal() { return count_sol == 1; }

sudoku::sudoku()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			chart[i][j] = 0;
	count_sol = 0;
}

istream& operator>>(istream& cin, sudoku& sd)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sd.chart[i][j];
	sd.count_sol = 0;
	return cin;
}

bool sudoku::write_in(int ix, int iy, int num)
{
	for (int j = 0; j < 9; j++)
	{
		if (j == iy) continue;
		if (chart[ix][j] == num) return false; 
		if (chart[ix][j] == 0)
		{
			if (possibchart[ix][j][num - 1] == true) possibnum[ix][j]--;
			possibchart[ix][j][num - 1] = false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == ix) continue;
		if (chart[i][iy] == num) return false;
		if (chart[i][iy] == 0)
		{
			if (possibchart[i][iy][num - 1] == true) possibnum[i][iy]--;
			possibchart[i][iy][num - 1] = false;
		}
	}
	int rgx = (ix / 3) * 3, rgy = (iy / 3) * 3;
	for (int i = rgx; i < rgx + 3; i++)
		for (int j = rgy; j < rgy + 3; j++)
		{
			if (i == ix && j == iy) continue;
			if (chart[i][j] == num) return false;
			if (chart[i][j] == 0)
			{
				if (possibchart[i][j][num - 1] == true) possibnum[i][j]--;
				possibchart[i][j][num - 1] = false;
			}
		}
	return true;
}

bool sudoku::init_possibchart()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++) possibchart[i][j][k] = true;
				possibnum[i][j] = 9;
			}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (chart[i][j] > 0)
				if (!write_in(i, j, chart[i][j])) return false;
	return true;
}

int sudoku::getminpossibind()
{
	int minpossib = 10;
	int res = -1;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (chart[i][j] == 0 && possibnum[i][j] < minpossib) 
			{ 
				minpossib = possibnum[i][j]; 
				res = i * 9 + j; 
			}
	return res;
}

void sudoku::solve_self()
{
	if (!init_possibchart()) { count_sol = 0; return; }
	solve_try();
}

bool sudoku::already_solved()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (chart[i][j] == 0) return false;
	return true;
}

void sudoku::solve_try()
{
	if (already_solved()) { count_sol++; /*print_chart();*/ return; }
	int minpossibind = getminpossibind();
	int nextx = minpossibind / 9;
	int nexty = minpossibind % 9;
	if (possibnum[nextx][nexty] == 0) return;
	for (int i = 0; i < 9; i++)
		if (possibchart[nextx][nexty][i])
		{
			chart[nextx][nexty] = i + 1;
			write_in(nextx, nexty, i + 1);
			solve_try();
			if (count_sol > 1) return;
			chart[nextx][nexty] = 0;
			init_possibchart();
		}
	return;
}

int main()
{
	sudoku sd; int T; cin >> T;
	while (T--)
	{
		cin >> sd; sd.solve_self();
		if (sd.isLegal()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}