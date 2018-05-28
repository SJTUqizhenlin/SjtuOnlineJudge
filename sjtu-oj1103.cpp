#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct guess
{
	string s; int n;
	guess() :s(""), n(0) {}
	bool operator<(const guess &rhs)const
	{
		return n > rhs.n;
	}
};

guess guesses[32]; //i:1->n
int dfsarr[32][13][11]; //i:depth, j:1->l, k:0->9(k==10 is restnum)
int maskarr[32][13];
int n, l; bool flag; string finalres;

void copydfs(int d)
{
	for (int j = 1; j <= l; j++)
		for (int k = 0; k <= 10; k++)
			dfsarr[d][j][k] = dfsarr[d - 1][j][k];
	return;
}

bool isMaskFit(int d)
{
	for (int j = 1; j <= l; j++)
	{
		int a = guesses[d].s[j - 1] - '0';
		if (maskarr[d][j])
		{
			if (dfsarr[d][j][a] == 2) return false;
		}
		else
		{
			if (dfsarr[d][j][a] == 1) return false;
		}
	}
	return true;
}

void fillMask(int d)
{
	for (int j = 1; j <= l; j++)
	{
		int a = guesses[d].s[j - 1] - '0';
		if (maskarr[d][j])
		{
			if (dfsarr[d][j][a] != 1)
			{
				for (int k = 0; k <= 9; k++) dfsarr[d][j][k] = 2;
				dfsarr[d][j][a] = 1;
				dfsarr[d][j][10] = 1;
			}
		}
		else
		{
			if (dfsarr[d][j][a] != 2)
			{
				dfsarr[d][j][a] = 2;
				dfsarr[d][j][10]--;
				if (dfsarr[d][j][10] == 1)
					for (int k = 0; k <= 9; k++)
						if (dfsarr[d][j][k] == 0) dfsarr[d][j][k] = 1;
			}
		}
	}
	return;
}

void storeRes()
{
	if (flag) return;
	flag = true;
	for (int j = 1; j <= l; j++)
	{
		for (int k = 0; k <= 9; k++)
			if (dfsarr[n][j][k] == 1)
			{
				finalres.append(1, (char)('0' + k));
				break;
			}
	}
	return;
}

void dfs(int d)
{
	if (flag) return;
	for (int j = 1; j <= l; j++) maskarr[d][j] = 0;
	for (int j = l; j > l - guesses[d].n; j--) maskarr[d][j] = 1;
	copydfs(d);
	do
	{
		if (isMaskFit(d))
		{
			fillMask(d);
			if (d == n) storeRes();
			else dfs(d + 1);
			copydfs(d);
		}
	} while (next_permutation(&(maskarr[d][1]), &(maskarr[d][l + 1])));
	return;
}

int main()
{
	cin >> n >> l;
	while (n > 0 || l > 0)
	{
		flag = false; finalres = "";
		for (int i = 1; i <= n; i++) cin >> guesses[i].s >> guesses[i].n;
		sort(guesses + 1, guesses + n + 1);
		for (int j = 1; j <= l; j++)
		{
			for (int k = 0; k <= 9; k++) dfsarr[0][j][k] = 0;
			dfsarr[0][j][10] = 10;
		}
		dfs(1);
		cout << finalres << endl;
		cin >> n >> l;
	}
	return 0;
}

/*

3 3
023 2
045 2
243 2

4 4
1999 1
9299 1
9939 1
9994 1

9 3
189 2
289 2
389 2
489 2
589 2
689 2
789 2
889 2
989 2

*/