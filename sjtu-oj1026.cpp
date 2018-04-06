//This is actually a model of HPint, which can be used anywhere High Precision is required
#include <iostream>
#include <string.h>

using namespace std;

const int maxlen = 10005;

class HPint
{
public:
	int len, s[maxlen];
	HPint() { len = 0; }
	friend ostream& operator<<(ostream& cout, const HPint &x);
	HPint operator=(int inte);
	HPint operator=(const char *strg);
	HPint operator=(const HPint& rhs);
	HPint operator+(const HPint& rhs) const;
	HPint operator*(const HPint& rhs) const;
	HPint operator-(const HPint& rhs) const;
	int Compare(const HPint& rhs) const;
	HPint operator/(const HPint& rhs) const;
};

ostream& operator<<(ostream& cout, const HPint &x)
{
	for (int i = x.len; i >= 1; i--) cout << x.s[i];
	return cout;
}

HPint HPint::operator=(int inte)
{
	if (inte == 0) { this->len = 1; this->s[1] = 0; return *this; }
	while (inte > 0)
	{
		this->len++;
		s[len] = inte % 10;
		inte /= 10;
	}
	return *this;
}

HPint HPint::operator=(const char* strg)
{
	len = strlen(strg);
	for (int i = 1; i <= len; i++) s[i] = strg[len - i] - '0';
	return *this;
}

HPint HPint::operator=(const HPint& rhs)
{
	len = rhs.len;
	for (int i = 1; i <= len; i++)
		s[i] = rhs.s[i];
	return *this;
}

HPint HPint::operator+(const HPint& rhs) const
{
	HPint res;
	res = 0;
	int i;
	for (i = 1; i <= this->len || i <= rhs.len || res.s[i]; i++)
	{
		if (i <= this->len) res.s[i] += this->s[i];
		if (i <= rhs.len) res.s[i] += rhs.s[i];
		res.s[i + 1] = res.s[i] / 10;
		res.s[i] %= 10;
	}
	res.len = i - 1;
	if (res.len == 0) res.len = 1;
	return res;
}

HPint HPint::operator*(const HPint& rhs) const
{
	int i, j;
	HPint res;
	res.len = this->len + rhs.len;
	for (i = 0; i <= res.len; i++) res.s[i] = 0;
	for (i = 1; i <= this->len; i++)
		for (j = 1; j <= rhs.len; j++)
		{
			res.s[i + j - 1] += this->s[i] * rhs.s[j];
		}
	for (i = 1; i < res.len; i++) { res.s[i + 1] += s[i] / 10; res.s[i] %= 10; }
	while (res.s[i]) { res.s[i + 1] += s[i] / 10; res.s[i] %= 10; i++; }
	while (i > 1 && !res.s[i]) i--;
	res.len = i;
	return res;
}

HPint HPint::operator-(const HPint& rhs) const
{
	int i, j;
	HPint res;
	for (i = 1, j = 0; i <= len; i++)
	{
		res.s[i] = s[i] - j;
		if (i <= rhs.len) res.s[i] -= rhs.s[i];
		if (res.s[i] < 0) { j = 1; res.s[i] += 10; }
		else j = 0;
	}
	res.len = len;
	while (res.len > 1 && !res.s[res.len]) res.len--;
	return res;
}

int HPint::Compare(const HPint& rhs) const
{
	if (len < rhs.len) return -1;
	if (len > rhs.len) return 1;
	int i = len;
	while (i > 1 && s[i] == rhs.s[i]) i--;
	return s[i] - rhs.s[i];
}

HPint HPint::operator/(const HPint& rhs) const
{
	int i, j;
	HPint d, c;
	d = 0;
	for (i = len; i > 0; i--)
	{
		if (!(d.len == 1 && d.s[1] == 0))
		{
			for (j = d.len; j > 0; j--) d.s[j + 1] = d.s[j];
			d.len++;
		}
		d.s[1] = s[i];
		c.s[i] = 0;
		while ((j = d.Compare(rhs)) >= 0)
		{
			d = d - rhs;
			c.s[i]++;
			if (j == 0) break;
		}
	}
	c.len = len;
	while (c.len > 1 && !c.s[c.len]) c.len--;
	return c;
}

int main()
{
	char a[maxlen];
	char b[maxlen];
	cin >> a >> b;
	bool isMinus = false;
	if (a[0] == '-' && b[0] != '-') isMinus = true;
	if (a[0] != '-' && b[0] == '-') isMinus = true;
	HPint biga, bigb;
	if (a[0] == '-') biga = &a[1]; else biga = &a[0];
	if (b[0] == '-') bigb = &b[1]; else bigb = &b[0];
	HPint c;
	c = biga / bigb;
	if (c.len == 1 && c.s[1] == 0) cout << "0" << endl;
	else
	{
		if (isMinus) cout << "-";
		cout << c << endl;
	}
	return 0;
}
