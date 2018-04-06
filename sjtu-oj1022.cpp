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