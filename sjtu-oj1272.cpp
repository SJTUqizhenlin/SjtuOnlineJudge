#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int divres[101][101];
int isexist[101];

void init_divres()
{
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			divres[i][j] = max(i, j) / min(i, j);
	return;
}

int main()
{
	init_divres();
	int n, val, Count = 0;
	cin >> n;
	vector<int> valvec;
	for (int i = 0; i < n; i++) { cin >> val; isexist[val] = 1; valvec.push_back(val); Count++; }
	while (true)
	{
		int Delta = 0;
		for (int i = 0; i < Count; i++)
			for (int j = i + 1; j < Count; j++)
				if (isexist[divres[valvec[i]][valvec[j]]] == 0)
				{
					isexist[divres[valvec[i]][valvec[j]]] = 1;
					valvec.push_back(divres[valvec[i]][valvec[j]]);
					Delta++;
				}
		if (Delta == 0) break;
		else Count += Delta;
	}
	cout << Count << endl;
	return 0;
}