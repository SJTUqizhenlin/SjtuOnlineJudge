#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int absol(int x)
{
	if (x >= 0) return x;
	return (0 - x);
}

struct camp
{
	int x, y, num;
	camp(int xx, int yy, int nnum) :x(xx), y(yy), num(nnum) {}
	bool operator<(const camp &rhs) { return num > rhs.num; }
};

int main()
{
	int m, n, k, tmp; cin >> m >> n >> k;
	vector<camp> v;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if (tmp > 0)
			{
				camp *newone = new camp(j, i, tmp);
				v.push_back(*newone);
			}
		}
	if (v.empty()) { cout << "0" << endl; return 0; }
	sort(v.begin(), v.end());
	int res = 0, campid = 0;
	if (k - v[0].y - 1 >= v[0].y) { res += v[0].num; k = k - v[0].y  - 1; }
	else { cout << "0" << endl; return 0; }
	while (++campid < v.size())
	{
		if (k - absol(v[campid].x - v[campid - 1].x)
			- absol(v[campid].y - v[campid - 1].y) - 1 >= v[campid].y)
		{
			res += v[campid].num;
			k = k - absol(v[campid].x - v[campid - 1].x)
				- absol(v[campid].y - v[campid - 1].y) - 1;
		}
		else break;
	}
	cout << res << endl;
	return 0;
}