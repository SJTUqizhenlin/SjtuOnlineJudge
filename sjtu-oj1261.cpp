#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> board;

bool isWon(char c)
{
	bool res;
	for (int i = 0; i < 4; i++)
	{
		res = true;
		for (int j = 0; j < 4; j++)
			if (board[i][j] != c && board[i][j] != 'T')
				res = false;
		if (res) return res;
	}
	for (int j = 0; j < 4; j++)
	{
		res = true;
		for (int i = 0; i < 4; i++)
			if (board[i][j] != c && board[i][j] != 'T')
				res = false;
		if (res) return res;
	}
	res = true;
	for (int i = 0; i < 4; i++)
		if (board[i][i] != c && board[i][i] != 'T')
			res = false;
	if (res) return res;
	res = true;
	for (int i = 0; i < 4; i++)
		if (board[i][3 - i] != c && board[i][3 - i] != 'T')
			res = false;
	if (res) return res;
	return false;
}

bool isComplete()
{
	int res = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] != '.') res++;
	return (res == 16);
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		board.clear();
		string tmp;
		for (int i = 0; i < 4; i++)
		{
			cin >> tmp; 
			board.push_back(tmp);
		}
		if (isWon('X')) cout << "X won\n";
		else
		{
			if (isWon('O')) cout << "O won\n";
			else
			{
				if (isComplete()) cout << "Draw\n";
				else cout << "Game has not completed\n";
			}
		}
	}
	return 0;
}