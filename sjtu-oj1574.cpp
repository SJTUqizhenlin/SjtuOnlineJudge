#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	int *store = new int[n];
	memset(store, 0, sizeof(int) * n);
	int *resarr = new int[n];
	long long tmp = m;
	int count = 0;
	int x1, x2;
	while (true)
	{
		tmp = (tmp * 10) % n;
		if (store[tmp] == 0)
		{
			count++;
			store[tmp] = count;
			resarr[count] = tmp;
		}
		else
		{
			count++;
			x1 = store[tmp];
			x2 = count;
			break;
		}
	}
	long long res;
	if (k < x2)
	{
		res = (resarr[k] + x) % n;
	}
	else
	{
		k = ((k - x1) % (x2 - x1)) + x1;
		res = (resarr[k] + x) % n;
	}
	cout << res << endl;
	return 0;
}