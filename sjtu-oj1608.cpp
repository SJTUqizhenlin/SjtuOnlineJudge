#include <iostream>
#include <string>
using namespace std;

class HPint
{
private:
	const static int maxlen = 100;
	int len;
	int *s;
public:
	int getlen() const;
	HPint();
	HPint(string stre);
	HPint operator=(const HPint &hpe);
	HPint operator=(string stre);
	HPint operator+(const HPint &b);
	string getString();
};

int HPint::getlen() const {
	return len;
}

HPint::HPint()
{
	len = 1;
	s = new int[maxlen];
	s[1] = 0;
}

HPint::HPint(string stre)
{
	len = stre.length();
	for (int i = 1; i <= len; i++)
		s[i] = stre[len - i] - '0';
	return;
}

HPint HPint::operator=(const HPint &hpe)
{
	len = hpe.len;
	for (int i = 1; i <= len; i++)
		s[i] = hpe.s[i];
	return (*this);
}

HPint HPint::operator=(string stre)
{
	len = stre.length();
	for (int i = 1; i <= len; i++)
		s[i] = stre[len - i] - '0';
	return (*this);
}

HPint HPint::operator+(const HPint &b)
{
	int i; HPint c;
	c.s[1] = 0;
	for (i = 1; i <= len || i <= b.len || c.s[i]; i++)
	{
		if (i <= len) c.s[i] += s[i];
		if (i <= b.len) c.s[i] += b.s[i];
		c.s[i + 1] = c.s[i] / 10; c.s[i] %= 10;
	}
	c.len = i - 1; if (c.len == 0) c.len = 1;
	return c;
}

string HPint::getString() {
	string ret = "";
	for (int i = len; i > 0; i--) ret.append(1, (char)(s[i] + '0'));
	return ret;
}

string stuf;

bool isOK(int beg, int end1, int end2) {
	int Len = stuf.length();
	HPint a, b, c;
	while (true) {
		a = stuf.substr(beg, end1 - beg + 1);
		b = stuf.substr(end1 + 1, end2 - end1);
		c = a + b;
		if (c.getlen() > Len - end2 - 1) return false;
		if (c.getString() != stuf.substr(end2 + 1, c.getlen())) return false;
		beg = end1 + 1;
		end1 = end2;
		end2 = end2 + c.getlen();
		if (end2 == Len - 1) break;
	}
	return true;
}

int main() {
	cin >> stuf; 
	int LEN = stuf.length();
	for (int i = 0; i < LEN; i++)
		for (int j = i + 1; j < LEN; j++)
			if (isOK(0, i, j)) { cout << 1; return 0; }
	cout << 0; return 0;
}