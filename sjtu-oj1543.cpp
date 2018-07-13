#include <iostream>

using namespace std;

//int extract3(int x)
//{
//	int res = 0;
//	while (x % 3 == 0)
//	{
//		x /= 3;
//		res++;
//	}
//	return res;
//}

long long func(long long x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	int r = x % 3;
	return (r + 1) * func(x / 3) + r;
}

int main()
{
	//for (int n = 1; n <= 1000; n++)
	//{
	//	int count = 0;
	//	int numOF3 = 0;
	//	for (int k = 1; k < n; k++)
	//	{
	//		numOF3 += extract3(n + 1 - k);
	//		numOF3 -= extract3(k);
	//		if (numOF3) count++;
	//	}
	//	cout << n << ": " <<  n - count << endl;
	//}

	long long n;
	cin >> n;
	cout << n - func(n) << endl;
	return 0;
}