#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
struct mat2x2
{
	long long a, b, c, d;
	mat2x2() :a(0), b(0), c(0), d(0) {}
	mat2x2(long long aa, long long bb, long long cc, long long dd)
		:a(aa), b(bb), c(cc), d(dd) {}
	mat2x2 operator*(const mat2x2 &m) const
	{
		mat2x2 res;
		res.a = a * m.a + b * m.c;
		res.a %= MOD;
		res.b = a * m.b + b * m.d;
		res.b %= MOD;
		res.c = a * m.c + c * m.d;
		res.c %= MOD;
		res.d = d * m.d + c * m.b;
		res.d %= MOD;
		return res;
	}
};

mat2x2 matseq[70];

void init_matseq()
{
	matseq[0] = mat2x2(1, 1, 1, 0);
	for (int i = 1; i <= 65; i++)
		matseq[i] = matseq[i - 1] * matseq[i - 1];
	return;
}

int main()
{
	init_matseq();
	long long n;
	cin >> n;
	int bitid = 0;
	mat2x2 res(1, 0, 0, 1);
	while (n)
	{
		if (n & 1)
			res = res * matseq[bitid];
		n >>= 1;
		bitid++;
	}
	cout << res.a << endl;
	return 0;
}