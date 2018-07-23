#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
	LL x, n, res = 0;
	cin >> x >> n;
	LL a = n % 7;
	for (int i = 0; i < a; i++)
	{
		if (x < 6) res += 250;
		x++; if (x > 7) x -= 7;
	}
	LL b = n / 7;
	res += b * 1250;
	cout << res;
	return 0;
}