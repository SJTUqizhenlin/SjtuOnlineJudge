#include <stdio.h>
using namespace std;

int PrimeArr[200];
int primenum;

bool isPrime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

void init_prime()
{
	primenum = 0;
	for (int i = 2; i <= 1050; i++)
		if (isPrime(i)) PrimeArr[primenum++] = i;
	return;
}

int basenum[2][200]; int pownum[2][200];
int bases[2]; long long rest[2];

void dealwith(long long x, int id)
{
	bases[id] = 0;
	for (int i = 0; i < primenum; i++)
	{
		if (x % PrimeArr[i] == 0)
		{
			basenum[id][bases[id]] = PrimeArr[i];
			pownum[id][bases[id]] = 0;
			while (x % PrimeArr[i] == 0)
			{
				pownum[id][bases[id]]++;
				x /= PrimeArr[i];
			}
			bases[id]++;
		}
		if (x == 1) break;
	}
	rest[id] = x;
	return;
}

int main()
{
	init_prime();
	int T; scanf("%d", &T);
	long long a, b;
	bool res;
	while (T--)
	{
		res = true;
		scanf("%lld%lld", &a, &b);
		if (a * a == b || b * b == a) { printf("Yes\n"); continue; }
		dealwith(a, 0);
		dealwith(b, 1);
		if (bases[0] != bases[1]) { printf("No\n"); continue; }
		else
		{
			int gr, ls;
			for (int i = 0; i < bases[0]; i++)
			{
				if (basenum[0][i] != basenum[1][i])
				{
					res = false;
					break;
				}
				gr = (pownum[0][i] > pownum[1][i] ? pownum[0][i] : pownum[1][i]);
				ls = pownum[0][i] + pownum[1][i] - gr;
				if (gr > ls * 2)
				{
					res = false;
					break;
				}
				ls -= (gr - ls);
				if (ls % 3 != 0)
				{
					res = false;
					break;
				}
			}
			if (!res) { printf("No\n"); continue; }
		}
		if (rest[0] != 1 || rest[1] != 1)
		{
			if (rest[0] * rest[0] == rest[1] || rest[1] * rest[1] == rest[0])
				printf("Yes\n");
			else printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}