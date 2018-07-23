#include <iostream>
using namespace std;

int main()
{
	int arr[105]; int n;
	cin >> n; int TotalN = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		TotalN += arr[i];
	}
	TotalN /= n;
	int RestN = 0, res = 0;
	for (int i = 0; i < n; i++)
	{
		RestN += (arr[i] - TotalN);
		if (RestN != 0) res++;
	}
	cout << res << endl;
	return 0;
}