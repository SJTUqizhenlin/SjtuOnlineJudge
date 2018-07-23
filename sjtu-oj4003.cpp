#include <iostream>

using namespace std;

int numOfone(int x)
{
	int res = 0;
	while (x)
	{
		x -= x & (-x);
		res++;
	}
	return res;
}

int reduceOne(int n, int x)
{
	for (int i = 0; i < x; i++)
		n -= n & (-n);
	n += n & (-n);
	return n;
}

int main()
{
	int n, k;
	cin >> n >> k;
	if (k >= n)
	{
		cout << k - n << endl;
		return 0;
	}
	int least = numOfone(n);
	if (least <= k)
	{
		cout << "0" << endl;
		return 0;
	}
	int tar;
	tar = reduceOne(n, least - k);
	cout << tar - n << endl;
	return 0;
}