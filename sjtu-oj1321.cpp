#include <iostream>
#include <vector>

using namespace std;

vector<long long> resvec[10];
int lastbit[4] = { 1, 3, 7, 9 };
int littleP[4] = { 2, 3, 5, 7 };

bool isPrime(long long x)
{
	bool res = true;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) { res = false; break; }
	return res;
}

int main()
{
	for (int i = 0; i < 4; i++) resvec[1].push_back(littleP[i]);
	int N; cin >> N;
	if (N >= 9) return 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < resvec[i - 1].size(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				long long test = resvec[i - 1][j] * 10 + lastbit[k];
				if (isPrime(test)) resvec[i].push_back(test);
			}
		}
	}
	for (int i = 0; i < resvec[N].size(); i++)
		cout << resvec[N][i] << endl;
	return 0;
}