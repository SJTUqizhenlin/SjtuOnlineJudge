#include <iostream>
using namespace std;

int arr[10] = { 0,1,3,6,0,5,1,8,6,5 };

int main()
{
	int T; cin >> T;
	long long n, res, tail, base;
	while (T--) {
		cin >> n;
		base = 1;
		tail = n % 10;
		res = (arr[tail] + arr[9] * (n / 10)) % 10;
		tail++;
		while (n) {
			n /= 10; base *= 10;
			res += ((n % 10 * tail) % 10) * base;
		}
		cout << res << endl;
	}
	return 0;
}