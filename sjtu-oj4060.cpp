#include <iostream>

using namespace std;

int arr[101];

int cal(int n)
{
	if (n <= 2)
		return 0;
	if (n == 3)
		return (arr[1] + arr[3]);
	int a = arr[n - 1] + arr[1];
	int b = arr[2] + arr[2];
	int tmp = (a > b ? (arr[n] + b) : (arr[n] + a)) + arr[1];
	return tmp + cal(n - 2);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	if (n <= 2) { cout << arr[n] << endl; return 0; }
	int res = cal(n) + arr[2];
	cout << res << endl;
	return 0;
}