#include <iostream>
#include <string>

using namespace std;

int main()
{
	int M, T, U, F, D;
	cin >> M >> T >> U >> F >> D;
	string a;
	int time = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> a;
		if (a == "u" || a == "d") time += (U + D);
		if (a == "f") time += (F + F);
		if (time > M)
		{
			cout << i;
			break;
		}
	}
	return 0;
}