#include <iostream>
#include <string>
using namespace std;

int main()
{
	long x1, x2; cin >> x1 >> x2;
	long long res = 0;
	if (x2 < 10) { cout << x2 - x1 + 1 << endl; return 0; }
	if (x1 < 10) res += (10 - x1);
	else
	{
		string s1 = to_string(x1);
		if (s1[0] >= s1[s1.length() - 1]) res += 1;
	}
	x1 -= (x1 % 10); x1 += 10;
	string s2 = to_string(x2);
	if (s2[0] <= s2[s2.length() - 1]) res += 1;
	x2 -= (x2 % 10);
	res = res + (x2 - x1) / 10;
	cout << res << endl;
	return 0;
}