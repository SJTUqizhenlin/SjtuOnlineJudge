#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1000005];
int arr1[10000005];
int lds[1000005];
int syst[1000005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
		arr[n - 1 - i] = arr1[i];
	}
	lds[0] = arr[0];
	int ldslen = 1;
	int pos = 0;
	for (int i = 1; i < n; i++)
	{
		pos = upper_bound(lds, lds + ldslen, arr[i]) - lds;
		lds[pos] = arr[i];
		if (pos == ldslen) ldslen++;
	}
	printf("%d\n", ldslen);
	syst[0] = arr1[0];
	int systnum = 1;
	pos = 0;
	for (int i = 1; i < n; i++)
	{
		pos = upper_bound(syst, syst + systnum, arr1[i]) - syst;
		syst[pos] = arr1[i];
		if (pos == systnum) systnum++;
	}
	printf("%d\n", systnum);
	return 0;
}