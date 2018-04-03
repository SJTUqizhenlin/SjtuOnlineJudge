#include <iostream>

using namespace std;

int main()
{
	int month = 1;
	int rare = 0;
	long long budget = 0;
	int saved = 0;
	for (; month <= 12; month++)
	{
		cin >> budget;
		rare += 300;
		if (rare < budget) { cout << (0 - month); break; }
		rare -= budget;
		saved += (rare / 100) * 100;
		rare = rare % 100;
		if (month == 12) cout << saved + saved / 5 + rare;
	}
	return 0;
}