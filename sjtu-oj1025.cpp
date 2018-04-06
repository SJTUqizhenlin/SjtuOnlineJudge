#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct point
{
	int val;
	int direc;
	point(int a, int b) :val(a), direc(b) {}
	point() : val(0), direc(-1) {}
};

bool compare(point a, point b)
{
	if (a.val == b.val) return (a.direc < b.direc);
	return (a.val < b.val);
}

int main()
{
	int N;
	cin >> N;
	point *parr = new point[2 * N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &parr[2 * i].val, &parr[2 * i + 1].val);
		parr[2 * i].direc = 0;
		parr[2 * i + 1].direc = 1;
	}
	sort(parr, parr + 2 * N, compare);
	int count_left = 1;
	int left_bound = parr[0].val;
	int res = 0;
	for (int i = 1; i < 2 * N; i++)
	{
		if (count_left == 0)
		{
			left_bound = parr[i].val;
		}
		if (parr[i].direc == 0) count_left++;
		else count_left--;
		if (count_left == 0) res += (parr[i].val - left_bound);
	}
	cout << res;
	return 0;
}