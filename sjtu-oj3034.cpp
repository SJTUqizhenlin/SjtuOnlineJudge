#include <iostream>
using namespace std;

bool isPrime(int a)
{
	if (a == 1) return false;
	if (a == 2) return true;
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0) return false;
	return true;
}

int main()
{
	int N; cin >> N;
	int l = N, r = N;
	while (!isPrime(l)) l--;
	while (!isPrime(r)) r++;
	cout << r - l;
	return 0;
}