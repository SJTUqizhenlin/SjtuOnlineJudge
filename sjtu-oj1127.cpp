#include <iostream>
#include <string>
using namespace std;

int T;
string s;
int F[201][201]; //store isSublist[l][r]

bool isEle(int l, int r);
bool isSublist(int l, int r);
bool isSet(int l, int r);
bool isLegal(int l, int r);

bool isEle(int l, int r)
{
	if (l == r) { F[l][r] = 1; return true; }
	if (isSet(l, r)) { F[l][r] = 1; return true; }
	return false;
}

bool isSublist(int l, int r)
{
	if (F[l][r] == 1) return true;
	if (F[l][r] == 2) return false;
	for (int i = l + 1; i < r; i++)
	{
		if (s[i] == ',')
			if (isEle(l, i - 1) && isSublist(i + 1, r))
			{F[l][r] = 1;return true;}
	}
	if (isEle(l, r))return true;
	else{F[l][r] = 2;return false;}
}

bool isSet(int l, int r)
{
	if (s[l] == '{' && s[r] == '}')
	{
		if (l + 1 == r) return true;
		return isSublist(l + 1, r - 1);
	}
	return false;
}

bool isLegal(int l, int r)
{
	for (int i = l; i <= r; i++)
		if (s[i] != '{' && s[i] != '}' && s[i] != ',') return false;
	return true;
}

void setF(int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) F[i][j] = 0;
	return;
}

int main()
{
	cin >> T;
	getline(cin, s);
	for (int t = 1; t <= T; t++)
	{
		getline(cin, s);
		int len = s.length();
		setF(len - 1);
		if (!isLegal(0, len - 1)) { cout << "Word #" << t << ": No Set\n"; continue; }
		if (isSet(0, len - 1)) cout << "Word #" << t << ": Set\n";
		else cout << "Word #" << t << ": No Set\n";
	}
	return 0;
}