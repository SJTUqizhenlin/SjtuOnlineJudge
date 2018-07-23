#include <iostream>
using namespace std;

inline long long maxof(long long a, long long b)
{
	return (a > b ? a : b);
}

inline long long minof(long long a, long long b)
{
	return (a < b ? a : b);
}

int main()
{
	long long x, y, x1, y1, res = 0;
	cin >> x >> y; 
	x1 = maxof(x, y); y1 = minof(x, y);
	while (x1 && y1)
	{
		res += ((4 * y1) * (x1 / y1));
		x = x1 % y1; y = y1;
		x1 = maxof(x, y); y1 = minof(x, y);
	}
	cout << res << endl;
	return 0;
}