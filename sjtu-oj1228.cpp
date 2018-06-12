#include <stdio.h>

using namespace std;

long long arr[405][405];
long long sumarr[405][405];

int main()
{
	long long n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) { scanf("%lld", &arr[i][j]); }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			sumarr[i][j] = arr[i][j] + sumarr[i - 1][j] + sumarr[i][j - 1] - sumarr[i - 1][j - 1];
		}
	long long Count = 0;
	for (int begrow = 1; begrow <= n; begrow++)
	{
		for (int edrow = begrow; edrow <= n; edrow++)
		{
			long long oddnum = 0;
			for (int col = 1; col <= n; col++)
				if ((sumarr[edrow][col] - sumarr[begrow - 1][col]) % 2) oddnum++;
			Count += oddnum * (n + 1 - oddnum);
		}
	}
	long long Total = n * (n + 1) * n * (n + 1) / 4;
	printf("%lld %lld\n", Count, (Total - Count));
	return 0;
}