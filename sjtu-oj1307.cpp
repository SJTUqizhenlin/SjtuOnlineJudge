#include <iostream>
#include <math.h>
using namespace std;

int topnum[50];

int searchSqrt(int l, int r, int x)
{
	if (l == r - 1) return l;
	int mid = (l + r) / 2;
	if (mid * mid <= x) return searchSqrt(mid, r, x);
	else return searchSqrt(l, mid, x);
}

bool isSquare(int x)
{
	int res = searchSqrt(1, x + 1, x);
	return (res * res == x);
}

int main()
{
	int N, M = 0; cin >> N; 
	while (++M)
	{
		int i;
		for (i = 0; i < N; i++)
			if (topnum[i] == 0 || isSquare(topnum[i] + M))
				break;
		if (i < N) topnum[i] = M;
		else { --M; break; }
	}
	cout << M << endl;
	return 0;
}