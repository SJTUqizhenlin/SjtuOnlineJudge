#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	vector<int> good(a, 0);
	vector<int> bad(b, 0);
	int tmp;
	for (int i = 0; i < a + b; i++)
	{
		cin >> tmp;
		if (i < a) good[i] = tmp;
		else bad[i - a] = tmp;
	}
	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	int count = a;
	int good_cur = a - 1;
	int bad_cur = b - 1;
	while (good_cur >= 0 && bad_cur >= 0)
	{
		while (bad[bad_cur] >= good[good_cur])
		{
			if (bad_cur == 0) break;
			bad_cur--;
		}
		if (good[good_cur] > bad[bad_cur])
		{
			count++;
			if (good_cur > 0) good_cur--; else break;
			if (bad_cur > 0) bad_cur--; else break;
		}
		else break;
	}
	cout << count;
	return 0;
}