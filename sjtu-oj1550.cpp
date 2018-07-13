#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[1005];
string srcs;

bool isNum(char c)
{
	return (c >= '0' && c <= '9');
}

int main()
{
	int n;
	cin >> n;
	getline(cin, srcs);
	getline(cin, srcs);
	int beg = 0, ed = 0, ind = 0;
	while (ind < n)
	{
		while (!isNum(srcs[beg])) beg++;
		ed = beg + 1;
		while (isNum(srcs[ed])) ed++;
		arr[ind] = stoi(srcs.substr(beg, ed - beg));
		ind++;
		beg = ed;
	}
	int sum1 = 0;
	int maxh = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += arr[i];
		maxh = max(maxh, arr[i]);
	}
	int l, r;
	for (int i = 0; i < n; i++)
		if (arr[i] == maxh) { l = i; break; }
	for (int i = n - 1; i >= 0; i--)
		if (arr[i] == maxh) { r = i; break; }
	int sum2 = (r - l + 1) * maxh;
	int cur_max = 0;
	for (int i = 0; i < l; i++)
	{
		if (arr[i] > cur_max) cur_max = arr[i];
		sum2 += cur_max;
	}
	cur_max = 0;
	for (int i = n - 1; i > r; i--)
	{
		if (arr[i] > cur_max) cur_max = arr[i];
		sum2 += cur_max;
	}
	printf("%d\n", (sum2 - sum1));
	return 0;
}