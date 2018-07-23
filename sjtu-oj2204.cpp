#include <iostream>
#include <string.h>
using namespace std;

class HPint
{
	friend ostream& operator<<(ostream &cout, const HPint &x);
	friend istream& operator>>(istream &cin, HPint &x);
private:
	const static int maxlen = 30;
	int len;
	int s[maxlen];
public:
	HPint();
	HPint(int inte);
	HPint operator=(const HPint &hpe);
	HPint operator=(int inte);
	HPint operator=(const char *stre);
	HPint operator+(const HPint &b);
	HPint operator+(int inte);
};

ostream& operator<<(ostream &cout, const HPint &x)
{
	for (int i = 1; i <= x.len; i++)
		cout << x.s[x.len + 1 - i];
	return cout;
}

istream& operator>>(istream &cin, HPint &x)
{
	char *stre = new char[x.maxlen];
	cin >> stre;
	int strelen = strlen(stre);
	x.len = strelen;
	for (int i = 1; i <= strelen; i++)
		x.s[i] = stre[strelen - i] - '0';
	return cin;
}

HPint::HPint()
{
	len = 1;
	s[1] = 0;
}

HPint::HPint(int inte)
{
	if (inte == 0) { len = 1; s[1] = 0; return; }
	int i = 0;
	while (inte)
	{
		s[++i] = inte % 10;
		inte /= 10;
	}
	len = i; return;
}

HPint HPint::operator=(const HPint &hpe)
{
	len = hpe.len;
	for (int i = 1; i <= len; i++)
		s[i] = hpe.s[i];
	return (*this);
}

HPint HPint::operator=(int inte)
{
	if (inte == 0) { len = 1; s[1] = 0; return (*this); }
	int i = 0;
	while (inte)
	{
		s[++i] = inte % 10;
		inte /= 10;
	}
	len = i; return (*this);
}

HPint HPint::operator=(const char *stre)
{
	len = strlen(stre);
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

HPint HPint::operator+(int inte)
{
	HPint b(inte);
	return ((*this) + b);
}

int weight[22], pos[22];
int m, n;
HPint dp[22][15001];

void init() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> pos[i];
	for (int i = 1; i <= n; i++) cin >> weight[i];
	return;
}

void fillDP() {
	dp[0][7500] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 15000; j++) {
			for (int k = 1; k <= m; k++) {
				if (j - weight[i] * pos[k] >= 0 && j - weight[i] * pos[k] <= 15000)
					dp[i][j] = dp[i][j] + dp[i - 1][j - weight[i] * pos[k]];
			}
		}
	}
	return;
}

int main() {
	init();
	fillDP();
	cout << dp[n][7500] << endl;
	return 0;
}

/*
This dfs method is RIGHT, but cost too much TIME
What's more, pruning can reduce time complexity,
but never reduce the level of time complexity.
*/

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int weight[30];
//int sufsum[30];
//int pos[30];
//int m, n;
//inline bool cmp(int &a, int &b) { return a > b; }
//long long res;
//
//void init() {
//	cin >> m >> n;
//	for (int i = 1; i <= m; i++) cin >> pos[i];
//	sort(pos + 1, pos + m + 1);
//	for (int i = 1; i <= n; i++) cin >> weight[i];
//	sort(weight + 1, weight + n + 1, cmp);
//	for (int i = n; i >= 1; i--)
//		sufsum[i] = sufsum[i + 1] + weight[i];
//	res = 0;
//	return;
//}
//
//void dfs(int wid, int mom) {
//	if (wid == n + 1) {
//		res += (mom == 0 ? 1 : 0);
//		return;
//	}
//	if (mom + (sufsum[wid] * pos[m]) < 0 ||
//		mom + (sufsum[wid] * pos[1]) > 0)
//		return;
//	for (int i = 1; i <= m; i++)
//		dfs(wid + 1, mom + (weight[wid] * pos[i]));
//	return;
//}
//
//int main() {
//	init();
//	dfs(1, 0);
//	cout << res << endl;
//	return 0;
//}

