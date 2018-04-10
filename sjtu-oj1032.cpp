#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Big_Int
{
	vector<int> content;
	int bit_num;

	Big_Int()
	{
		bit_num = 1;
		content.push_back(0);
	}

	Big_Int(string s)
	{
		for (int i = 0; i < s.length(); i++)
			content.push_back(s[s.length() - 1 - i] - '0');
		bit_num = s.length();
	}

	Big_Int(vector<int> v)
	{
		for (int i = 0; i < v.size(); i++)
			content.push_back(v[i]);
		bit_num = v.size();
	}

	string present()
	{
		string res = "";
		for (int i = bit_num - 1; i >= 0; i--)
			res.append(1, (content[i] + '0'));
		return res;
	}

	void operator=(Big_Int another)
	{
		content.clear();
		for (int i = 0; i < another.content.size(); i++)
			content.push_back(another.content[i]);
		bit_num = another.bit_num;
	}

	Big_Int plus(Big_Int &another)
	{
		vector<int> res;
		int cur = 0, next = 0;
		int bit_cur = 0;
		while (this->bit_num > bit_cur && another.bit_num > bit_cur)
		{
			cur = next + this->content[bit_cur] + another.content[bit_cur];
			next = cur / 10;
			cur = cur % 10;
			res.push_back(cur);
			bit_cur++;
		}
		while (this->bit_num > bit_cur)
		{
			cur = next + this->content[bit_cur];
			next = cur / 10;
			cur = cur % 10;
			res.push_back(cur);
			bit_cur++;
		}
		while (another.bit_num > bit_cur)
		{
			cur = next + another.content[bit_cur];
			next = cur / 10;
			cur = cur % 10;
			res.push_back(cur);
			bit_cur++;
		}
		if (next != 0) res.push_back(next);
		Big_Int b(res);
		return b;
	}
	Big_Int mutiply(Big_Int &another)
	{
		vector<int> res(this->bit_num + another.bit_num, 0);
		for (int j = 0; j < another.bit_num; j++)
		{
			for (int i = 0; i < this->bit_num; i++)
			{
				int tmp = this->content[i] * another.content[j] + res[j + i];
				res[j + i] = tmp % 10;
				res[j + i + 1] += tmp / 10;
			}
		}
		while (res[res.size() - 1] == 0 && res.size() > 1) res.pop_back();
		Big_Int b(res);
		return b;
	}

	Big_Int divide_by(Big_Int &another)
	{
		string res = "";
		if (this->compare(another) == -1) return Big_Int("0");
		int tail = another.bit_num;
		string part = this->present().substr(0, another.bit_num);
		Big_Int part_big(part);
		int onebit = 0;
		Big_Int inside("0");
		while (true)
		{
			while (true)
			{
				onebit++;
				inside = inside.plus(another);
				if (inside.compare(part_big) == 1) break;
			}
			inside = inside.minus(another);
			onebit--;
			if (tail + 1 <= this->bit_num)
			{
				part = part_big.minus(inside).present();
				part.append(1, (this->content[bit_num - tail - 1] + '0'));
				while (part[0] == '0' && part.length() > 1) part.erase(0, 1);
				part_big = Big_Int(part);
				tail++;
			}
			else break;
			res.append(1, (onebit + '0'));
			onebit = 0;
			inside = Big_Int("0");
		}
		while (true)
		{
			onebit++;
			inside = inside.plus(another);
			if (inside.compare(part_big) == 1) break;
		}
		inside = inside.minus(another);
		onebit--;
		res.append(1, (onebit + '0'));
		if (res[0] == '0' && res.length() > 1) res.erase(0, 1);
		return Big_Int(res);
	}

	int compare(Big_Int &another)
	{
		if (bit_num < another.bit_num) return -1;
		if (bit_num > another.bit_num) return 1;
		for (int i = bit_num - 1; i >= 0; i--)
		{
			if (content[i] == another.content[i]) continue;
			if (content[i] > another.content[i]) return 1;
			if (content[i] < another.content[i]) return -1;
		}
		return 0;
	}

	Big_Int minus(Big_Int &another)
	{
		vector<int> res;
		if (this->compare(another) == 0) return Big_Int("0");
		if (this->compare(another) == -1) return Big_Int("0");
		if (this->compare(another) == 1)
		{
			int cur = 0, next = 0;
			int bit_cur = 0;
			while (bit_cur < another.bit_num)
			{
				cur = next + content[bit_cur] - another.content[bit_cur];
				if (cur < 0) { next = -1; cur += 10; }
				else next = 0;
				res.push_back(cur);
				bit_cur++;
			}
			while (bit_cur < bit_num)
			{
				cur = next + content[bit_cur];
				if (cur < 0) { next = -1; cur += 10; }
				else next = 0;
				res.push_back(cur);
				bit_cur++;
			}
		}
		while (res[res.size() - 1] == 0) res.pop_back();
		Big_Int b(res);
		return b;
	}
};

int main()
{
	int m, n;
	cin >> m >> n;
	if (m == 0)
		cout << n + 1 << endl;
	if (m == 1)
		cout << n + 2 << endl;
	if (m == 2)
		cout << 2 * n + 3 << endl;
	if (m == 3)
	{
		Big_Int res("1");
		Big_Int two("2");
		for (int i = 0; i < n + 3; i++)
		{
			res = res.mutiply(two);
		}
		Big_Int three("3");
		res = res.minus(three);
		cout << res.present() << endl;
	}
	return 0;
}