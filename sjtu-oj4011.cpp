#include <iostream>
#include <string.h>

using namespace std;

const int maxlen = 200;

class HPint
{
public:
	int len, s[maxlen];
	HPint() { len = 0; }
	friend ostream& operator<<(ostream& cout, const HPint &x);
	HPint operator=(int inte);
	HPint operator=(const HPint& rhs);
	HPint operator+(const HPint& rhs) const;
};

ostream& operator<<(ostream& cout, const HPint &x)
{
	for (int i = x.len; i >= 1; i--) cout << x.s[i];
	return cout;
}

HPint HPint::operator=(int inte)
{
	this->len = 0;
	if (inte == 0) { this->len = 1; this->s[1] = 0; return *this; }
	while (inte > 0)
	{
		this->len++;
		s[len] = inte % 10;
		inte /= 10;
	}
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

int main()
{
	int k, h;
	cin >> k >> h;
	HPint **arr = new HPint*[h + 1];
	for (int i = 0; i <= h; i++)
	{
		arr[i] = new HPint[k + 1];
		for (int j = 0; j <= k; j++)
			arr[i][j] = 0;
	}
	arr[1][1] = 1;
	for (int i = 1; i < h; i++)
	{
		HPint tmp;
		tmp = 0;
		for (int j = 1; j <= k; j++)
		{
			tmp = tmp + arr[i][j];
			arr[i + 1][k + 1 - j] = tmp;
		}
	}
	HPint res;
	res = 0;
	for (int i = 1; i <= k; i++)
		res = res + arr[h][i];
	cout << res << endl;
	return 0;
}