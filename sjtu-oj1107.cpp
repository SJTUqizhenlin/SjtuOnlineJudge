// here is a very magic proof for this result,
// when x >= 1, first to go, first to win

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
