#include <stdio.h>
#include <algorithm>
typedef long long LL;
using namespace std;

struct flag
{
	LL val; int type;
	flag() :val(0), type(0) {}
	bool operator<(const flag &b) const
	{
		if (val == b.val) return type < b.type;
		return val < b.val;
	}
};

flag arr[10005 * 2];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &(arr[i * 2].val));
		scanf("%lld", &(arr[i * 2 + 1].val));
		arr[i * 2].type = 1;
		arr[i * 2 + 1].type = 2;
	}
	sort(arr, arr + n * 2);
	int Count_l = 0, l = 0, r = 0;
	LL res = 0;
	while (r < n * 2)
	{
		if (arr[r].type == 1) Count_l++;
		else
		{
			Count_l--;
			if (Count_l == 0)
			{
				res += (arr[r].val - arr[l].val);
				l = r + 1;
			}
		}
		r++;
	}
	printf("%lld\n", res);
	return 0;
}