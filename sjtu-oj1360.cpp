#include <stdio.h>
#include <algorithm>
using namespace std;

struct timeseg
{
	int beg, end;
	timeseg() :beg(0), end(0) {}
	timeseg(int bbeg, int eend) :beg(bbeg), end(eend) {}
	bool operator<(const timeseg &rhs) const
	{
		return end < rhs.end;
	}
};
timeseg arr[100005];

int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d%d", &(arr[i].beg), &(arr[i].end));
	sort(arr, arr + N);
	int Count = 0, endtime = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].beg >= endtime)
		{
			Count++;
			endtime = arr[i].end;
		}
	}
	printf("%d\n", Count);
	return 0;
}