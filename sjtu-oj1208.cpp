#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double maxres = 0;
	double a, r, tmp;
	while (cin >> r >> a)
	{
		tmp = acos(a / r) * r * r;
		tmp -= a * sqrt(r * r - a * a);
		if (tmp > maxres) maxres = tmp;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << maxres << endl;
	return 0;
}