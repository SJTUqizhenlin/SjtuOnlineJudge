#include <iostream>
#include <string>
typedef long long LL;
using namespace std;

inline LL min(LL a, LL b) {
	return (a < b ? a : b);
}

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	LL r1 = 0, r2, r3;
	LL sn = 0, tn = 0, an = 0, rn = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'S') sn++;
		if (s[i] == 'T') tn++;
		if (s[i] == 'A') an++;
		if (s[i] == 'R') rn++;
	}
	r3 = sn * tn * an *rn;
	cout << r3 << " ";
	r2 = 2000;
	if (sn < r2) r2 = sn;
	if (tn < r2) r2 = tn;
	if (an < r2) r2 = an;
	if (rn < r2) r2 = rn;
	cout << r2 << " ";
	sn = tn = an = rn = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'S') sn++;
		if (s[i] == 'T') tn++;
		if (s[i] == 'A') an++;
		if (s[i] == 'R') rn++;
		tn = min(sn, tn);
		an = min(tn, an);
		rn = min(an, rn);
	}
	r1 = rn;
	cout << r1;
	return 0;
}