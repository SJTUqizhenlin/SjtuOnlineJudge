#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

const int maxval = 2000002;
int uomap[maxval * 2 + 1];

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> vecarr[4];
	set<int> setarr[4];
	int arr[4];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++) scanf("%d", &arr[j]);
		for (int j = 0; j < 4; j++) /*if (setarr[j].find(arr[j]) == setarr[j].end())*/ { setarr[j].insert(arr[j]); vecarr[j].push_back(arr[j]); }
	}
	for (int i = 0; i < vecarr[0].size(); i++)
		for (int j = 0; j < vecarr[1].size(); j++)
			uomap[vecarr[0][i] + vecarr[1][j] + maxval] += 1;
	long long res = 0;
	for (int i = 0; i < vecarr[2].size(); i++)
		for (int j = 0; j < vecarr[3].size(); j++)
			res += uomap[(maxval - vecarr[2][i] - vecarr[3][j])];
	printf("%lld\n", res);
	return 0;
}