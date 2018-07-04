#include <stdio.h>
#include <cmath>
#include <algorithm>

const double epsi = 3 * 1e-6;
double o[505], r[505], xl[505], yl[505], xr[505], yr[505];
int n;
double ubound = 0 - 1e3, lbound = 1e6;

void init_xylr()
{
	double tmpcos, tmpsin;
	for (int i = 1; i <= n; i++)
	{
		tmpcos = (r[i] - r[i + 1]) / (o[i + 1] - o[i]);
		if (fabs(tmpcos) > 1) { xl[i] = o[i]; xr[i] = o[i + 1]; yl[i] = yr[i] = 0; continue; }
		tmpsin = sqrt(1 - tmpcos * tmpcos);
		xl[i] = o[i] + tmpcos * r[i];
		yl[i] = tmpsin * r[i];
		xr[i] = o[i + 1] + tmpcos * r[i + 1];
		yr[i] = tmpsin * r[i + 1];
	}
	return;
}

double func(double x)
{
	double res = 0, tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fabs(o[i] - x) < r[i])
		{
			tmp = sqrt(r[i] * r[i] - (o[i] - x) * (o[i] - x));
			if (tmp > res) res = tmp;
		}
		if (xl[i] < x && xr[i] > x)
		{
			tmp = yl[i] + (yr[i] - yl[i]) * ((x - xl[i]) / (xr[i] - xl[i]));
			if (tmp > res) res = tmp;
		}
	}
	return res;
}

double simpson(double l, double r)
{
	return (((r - l) / 6) * (func(l) + func(r) + 4 * func((l + r) / 2)));
}

double area(double l, double r)
{
	double mid = (l + r) / 2;
	double curres = simpson(l, r);
	double nxtres = simpson(l, mid) + simpson(mid, r);
	if (fabs(curres - nxtres) < epsi) return curres;
	else return(area(l, mid) + area(mid, r));
}

int main()
{
	scanf("%d", &n);
	double alpha; scanf("%lf", &alpha);
	alpha = 1 / tan(alpha);
	
	double totalheight = 0, tmpheight = 0;
	for (int i = 0; i <= n; i++)
	{
		scanf("%lf", &tmpheight); totalheight += tmpheight;
		o[i + 1] = totalheight * alpha;
	}
	for (int i = 1; i <= n; i++) 
	{ 
		scanf("%lf", &r[i]); 
		if (o[i] - r[i] < lbound) lbound = o[i] - r[i];
		if (o[i] + r[i] > ubound) ubound = o[i] + r[i];
	}
	r[n + 1] = 0;
	if (o[n + 1] - r[n + 1] < lbound) lbound = o[n + 1] - r[n + 1];
	if (o[n + 1] + r[n + 1] > ubound) ubound = o[n + 1] + r[n + 1];

	init_xylr();

	double res = 2 * area(lbound, ubound);
	printf("%.2lf\n", res);
	return 0;
}