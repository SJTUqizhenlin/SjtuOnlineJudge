#include <iostream>
#include <vector>

using namespace std;

int Bitsum(long long x)
{
	int res = 0;
	while (x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

long long Calcu(int x, int k, int p, int q)
{
	long long res = 1;
	for (int i = 0; i < k; i++)
		res *= x;
	res *= p;
	res += q;
	return res;
}

int main()
{
	int k, p, q;
	cin >> k >> p >> q;
	int l, r;
	cin >> l >> r;
	vector<long long> v;
	for (int i = 0; i <= 81; i++)
	{
		long long big = Calcu(i, k, p, q);
		if ((big >= l && big <= r) && Bitsum(big) == i) v.push_back(big);
	}
	cout << v.size() << endl;
	if (v.size())
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	else cout << "-1";
	cout << endl;
	return 0;
}