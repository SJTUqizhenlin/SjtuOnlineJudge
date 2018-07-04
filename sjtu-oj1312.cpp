#include <iostream>
using namespace std;

int main()
{
	int n, k, T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		if (k == 1)
		{
			if (n % 2 == 0) cout << "Yeah!" << endl;
			else cout << "5555" << endl;
		}
		else
		{
			if (n <= k) cout << "5555" << endl;
			else cout << "Yeah!" << endl;
		}
	}
	return 0;
}