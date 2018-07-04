#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct fraction
{
	int numerator, denominator;
	fraction(int n, int d) :numerator(n), denominator(d) {}
	bool operator<(const fraction &rhs) const
	{
		return numerator * rhs.denominator < denominator * rhs.numerator;
	}
};

int g_c_d(int x, int y)
{
	int tmp = y % x;
	while (tmp)
	{
		y = x;
		x = tmp;
		tmp = y % x;
	}
	return x;
}

int main()
{
	vector<fraction> v;
	int N; scanf("%d", &N);
	printf("0/1\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (g_c_d(j, i) == 1)
				v.push_back(fraction(j, i));
		}
	}
	sort(v.begin(), v.end());
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) printf("%d/%d\n", v[i].numerator, v[i].denominator);
	printf("1/1\n");
	return 0;
}