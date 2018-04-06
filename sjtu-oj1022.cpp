//In this problem, answer is mod by 2010,
//and fib sequence f(n) is only related to
//f(n - 1) and f(n - 2), so "f(n) mod 2010"
//will be in loop with length less than 2010^2,
//but by experiment, looplen==2041
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[2041];
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= 2040; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 2010;
	}
	long long n;
	cin >> n;
	cout << arr[(n - 1) % 2040 + 1];
	return 0;
}
