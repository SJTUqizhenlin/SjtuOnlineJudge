#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *K = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &K[i]);
	}
	int res = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		res = (res + K[i] - 1) % (n - i) + 1;
	}
	cout << res << endl;
	return 0;
}