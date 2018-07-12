#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bitarr[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int calcu(int n)
{
	if (n == 0) return 6;
	int res = 0;
	while (n)
	{
		res += bitarr[n % 10];
		n /= 10;
	}
	return res;
}

int main()
{
	vector<vector<int> > v;
	for (int i = 0; i <= 20; i++)
	{
		vector<int> vi;
		v.push_back(vi);
	}
	for (int num = 0; num <= 999; num++)
	{
		int x = calcu(num);
		if (x <= 20)
			v[x].push_back(num);
	}
	int n;
	cin >> n;
	n -= 3;
	int Count = 0;
	for (int i = 2; i <= 16; i++)
		for (int j = i; j <= 16; j++)
		{
			if (i + j > n - 2) continue;
			int k = n - i - j;
			for (int p = 0; p < v[i].size(); p++)
				for (int q = 0; q < v[j].size(); q++)
				{
					int pos = lower_bound(v[k].begin(), v[k].end(), v[i][p] + v[j][q]) - v[k].begin();
					if (pos != v[k].size() && v[k][pos] == v[i][p] + v[j][q])
					{
						if (i != j) Count += 2;
						else Count += 1;
					}
				}
		}
	cout << Count << endl;
	return 0;
}