#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct HPint
{
	static const int maxlen = 5000;
	int len, s[maxlen];
	HPint()
	{
		len = 1;
		s[1] = 0;
	}
	friend ostream& operator<<(ostream& cout, const HPint &x);
	HPint operator=(int inte);
	HPint operator=(string s);
	HPint& operator=(const HPint &rhs);
	HPint operator+(const HPint &rhs) const;
};

ostream& operator<<(ostream &cout, const HPint &x)
{
	for (int i = x.len; i >= 1; i--)
		cout << x.s[i];
	return cout;
}
HPint HPint::operator=(int inte)
{
	if (inte == 0) { len = 1; s[1] = 0; return *this; }
	for (len = 0; inte > 0;)
	{
		s[++len] = inte % 10;
		inte /= 10;
	}
	return *this;
}

HPint HPint::operator=(string stre)
{
	len = stre.length();
	for (int i = 1; i <= len; i++)
	{
		s[i] = stre[len - i] - '0';
	}
	return *this;
}
HPint& HPint::operator=(const HPint &rhs)
{
	len = rhs.len;
	for (int i = 1; i <= len; i++) s[i] = rhs.s[i];
	return *this;
}

HPint HPint::operator+(const HPint &rhs) const
{
	HPint res;
	int i;
	for (i = 1; i <= len || i <= rhs.len || res.s[i]; i++)
	{
		if (i <= len) res.s[i] += s[i];
		if (i <= rhs.len) res.s[i] += rhs.s[i];
		res.s[i + 1] = res.s[i] / 10;
		res.s[i] %= 10;
	}
	res.len = i - 1;
	if (res.len == 0) res.len = 1;
	return res;
}

HPint h0, h1, h2, tmp0, tmp1, tmp2;

int main()
{
	int n;
	cin >> n;
	if (n == 1) { cout << "2" << endl; return 0; }
	h0 = 1;
	h1 = 2;
	h2 = 1;
	for (int i = 2; i < n; i++)
	{
		tmp0 = tmp1 = tmp2 = 0;
		tmp0 = h2;
		tmp1 = h0 + h1 + h2;
		tmp2 = h1;
		h0 = tmp0; h1 = tmp1; h2 = tmp2;
	}
	cout << (h0 + h1 + h2) << endl;
	return 0;
}