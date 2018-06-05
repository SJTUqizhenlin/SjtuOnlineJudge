#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long maxnum = max(a, b);
	long long minnum = min(a, b);
	long long tmp;
	while (maxnum % minnum != 0)
	{
		tmp = maxnum % minnum;
		maxnum = minnum;
		minnum = tmp;
	}
	return minnum;
}

int decbitnum(long long x)
{
	int res = 1;
	long long m = 10;
	while (m <= x) { m *= 10; res++; }
	return res;
}

struct ratnum
{
	long long up, down;
	ratnum() :up(0), down(1) {}
	ratnum(long long ix) :up(ix), down(1) {}
	ratnum(long long a, long long b) :up(a), down(b) { simp(); }
	void simp()
	{
		long long divs = gcd(up, down);
		up /= divs;
		down /= divs;
	}
	ratnum operator+(const ratnum &rhs) const
	{
		long long rdown = down * rhs.down;
		long long rup = up * rhs.down + down * rhs.up;
		ratnum* res = new ratnum(rup, rdown);
		return *res;
	}
};

ostream& operator<<(ostream &cout, const ratnum &rx)
{
	long long z = rx.up / rx.down;
	long long a = rx.up % rx.down;
	long long b = rx.down;
	int wz = decbitnum(z);
	int wa = decbitnum(a);
	int wb = decbitnum(b);
	if (a == 0) { cout << z; return cout; }
	if (z > 0)
	{
		for (int i = 0; i < wz + 1; i++) cout << ' ';
		cout << a << endl;
		cout << z << " ";
		for (int i = 0; i < wb; i++) cout << '-';
		cout << endl;
		for (int i = 0; i < wz + 1; i++) cout << ' ';
		cout << b;
	}
	else
	{
		cout << a << endl;
		for (int i = 0; i < wb; i++) cout << '-';
		cout << endl;
		cout << b;
	}
	return cout;
}

int main()
{
	int n;
	cin >> n;
	ratnum res;
	for (int i = n; i >= 1; i--)
		res = res + ratnum(n, i);
	cout << res << endl;
	return 0;
}