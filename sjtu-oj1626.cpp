#include <iostream>
using namespace std;

int coinarr[6] = { 100, 50, 10, 5, 2, 1 };

int getNum(int x)
{
	int res = 0;
	for (int i = 0; i < 6; i++)
	{
		res += (x / coinarr[i]);
		x = x % coinarr[i];
	}
	return res;
}

bool isPrime(long long x)
{
	if (x <= 1) return false;
	for (int d = 2; d * d <= x; d++)
		if (x % d == 0) return false;
	return true;
}

int main()
{
	int arr[101], n, numofcoin = 0;
	cin >> n;
	long long sumofarr = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		numofcoin += getNum(arr[i]);
		sumofarr += arr[i];
	}
	cout << numofcoin << endl;
	if (isPrime(sumofarr))
		cout << sumofarr << " is a prime number\n";
	else
		cout << sumofarr << " is not a prime number\n";
	return 0;
}