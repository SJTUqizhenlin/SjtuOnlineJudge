#include <iostream>

using namespace std;

int arr[10] = { 0,1,3,6,0,5,1,8,6,5 };

int main()
{
	int T;
	long long n, ntail, res;
	cin >> T;
	while (T--)
	{
		cin >> n;
		res = 0;
		ntail = n % 10;
		res += (arr[ntail] + ((n / 10) % 2) * arr[9]) % 10;
		long long base = 1;
		while (base * 10 <= n)
		{
			base *= 10;
			res += ((((n / base) % 10) * (ntail + 1)) % 10) * base;
		}
		cout << res << endl;
	}
	return 0;
}