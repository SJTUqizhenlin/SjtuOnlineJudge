#include <iostream>

using namespace std;

int arr[30];

void init()
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 27; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	return;
}

int main()
{
	init();
	int n;
	cin >> n;
	cout << arr[n] << endl;
	return 0;
}