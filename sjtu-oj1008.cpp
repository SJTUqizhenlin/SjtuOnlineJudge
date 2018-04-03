#include <iostream>
#include <string>

using namespace std;

struct Date
{
	int y;
	int m;
	int d;
	int t; // total days from 0000-01-01
	int w; // total weeks
	int wd; //week day: 1-Saturday, 2-Sunday, 3-Monday...
	int mon1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int mon2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	bool isleap()
	{
		if (y % 4 != 0) return false;
		if (y % 100 == 0 && y % 400 != 0) return false;
		return true;
	}
	Date(string s) // s is date string: XXXX-XX-XX
	{
		y = stoi(s.substr(0, 4));
		m = stoi(s.substr(5, 2));
		d = stoi(s.substr(8, 2));
		this->cal_t();
		this->cal_w();
	}
	Date(int year, int month, int day)
	{
		y = year;
		m = month;
		d = day;
		this->cal_t();
		this->cal_w();
	}
	void cal_t()
	{
		t = 0;
		if (y > 0)
		{
			t = t + y * 365;
			t = t + (y - 1) / 4 + 1;
			t = t - (y - 1) / 100 - 1;
			t = t + (y - 1) / 400 + 1;
		}
		for (int i = 0; i < m - 1; i++)
		{
			if (this->isleap())
				t = t + mon2[i];
			else t = t + mon1[i];
		}
		t = t + d;
	}
	void cal_w()
	{
		w = (t - 1) / 7 + 1;
		wd = (t - 1) % 7 + 1;
	}
	bool isBefore(Date another)
	{
		if (this->y < another.y) return true;
		if (this->y > another.y) return false;
		if (this->m < another.m) return true;
		if (this->m > another.m) return false;
		if (this->d <= another.d) return true;
		return false;
	}
	bool isAfter(Date another)
	{
		if (this->y > another.y) return true;
		if (this->y < another.y) return false;
		if (this->m > another.m) return true;
		if (this->m < another.m) return false;
		if (this->d >= another.d) return true;
		return false;
	}
};

int detect_holiday(Date d1, Date d2)
{
	int sum = 0;
	if (d1.y == d2.y)
	{
		Date h1(d1.y, 1, 1);
		if (h1.isAfter(d1) && h1.isBefore(d2))
			if (h1.wd > 2) sum++;
		for (int j = 1; j <= 3; j++)
		{
			Date h2(d1.y, 5, j);
			if (h2.isAfter(d1) && h2.isBefore(d2))
				if (h2.wd > 2) sum++;
		}
		for (int j = 1; j <= 7; j++)
		{
			Date h3(d1.y, 10, j);
			if (h3.isAfter(d1) && h3.isBefore(d2))
				if (h3.wd > 2) sum++;
		}
	}
	else
	{
		for (int i = d1.y + 1; i < d2.y; i++)
		{
			Date h1(i, 1, 1);
			if (h1.wd > 2) sum++;
			for (int j = 1; j <= 3; j++)
			{
				Date h2(i, 5, j);
				if (h2.wd > 2) sum++;
			}
			for (int j = 1; j <= 7; j++)
			{
				Date h3(i, 10, j);
				if (h3.wd > 2) sum++;
			}
		}
		Date h1(d1.y, 1, 1);
		if (h1.isAfter(d1))
			if (h1.wd > 2) sum++;
		for (int j = 1; j <= 3; j++)
		{
			Date h2(d1.y, 5, j);
			if (h2.isAfter(d1))
				if (h2.wd > 2) sum++;
		}
		for (int j = 1; j <= 7; j++)
		{
			Date h3(d1.y, 10, j);
			if (h3.isAfter(d1))
				if (h3.wd > 2) sum++;
		}
		Date h4(d2.y, 1, 1);
		if (h4.isBefore(d2))
			if (h4.wd > 2) sum++;
		for (int j = 1; j <= 3; j++)
		{
			Date h5(d2.y, 5, j);
			if (h5.isBefore(d2))
				if (h5.wd > 2) sum++;
		}
		for (int j = 1; j <= 7; j++)
		{
			Date h6(d2.y, 10, j);
			if (h6.isBefore(d2))
				if (h6.wd > 2) sum++;
		}
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		Date d1(s1);
		Date d2(s2);
		int ans = 0;
		ans = ans + (d2.w - d1.w - 1) * 5;
		ans = ans + (d1.wd < 3 ? 5 : (8 - d1.wd));
		ans = ans + (d2.wd > 2 ? (d2.wd - 2) : 0);
		ans = ans - detect_holiday(d1, d2);
		cout << ans << endl;
	}
	return 0;
}