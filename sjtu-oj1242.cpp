#include <iostream>

using namespace std;

int arr[10001];

int main()
{
	arr[1] = arr[0] = 1;
	for (int i = 2; i <= 100; i++)
	{
		if (!arr[i])
			for (int j = 2; i * j <= 10000; j++)
				arr[i * j] = 1;
	}
	int a, b, res = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
		if (!arr[i]) res++;
	cout << res << endl;
	return 0;
}