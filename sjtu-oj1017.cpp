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
	int a, b, c, N, n;
	cin >> a >> b >> c >> n;
	vector<int> tmpvec1;
	int tmp1 = a;
	while (tmp1 > 0)
	{
		tmpvec1.push_back(tmp1 % 10);
		tmp1 /= 10;
	}
	Big_Int a_big(tmpvec1);
	tmpvec1.clear();
	tmp1 = b;
	while (tmp1 > 0)
	{
		tmpvec1.push_back(tmp1 % 10);
		tmp1 /= 10;
	}
	Big_Int b_big(tmpvec1);
	tmpvec1.clear();
	tmp1 = c;
	while (tmp1 > 0)
	{
		tmpvec1.push_back(tmp1 % 10);
		tmp1 /= 10;
	}
	Big_Int c_big(tmpvec1);
	N = (n >= 6 ? n : 6);
	Big_Int *arr = new Big_Int[N + 1];
	vector<int> tmpvec;
	arr[0] = Big_Int("1");
	int tmp = 1 + a;
	while (tmp > 0)
	{
		tmpvec.push_back(tmp % 10);
		tmp /= 10;
	}
	arr[1] = Big_Int(tmpvec);
	tmpvec.clear();
	tmp = 1 + a + b + a * a;
	while (tmp > 0)
	{
		tmpvec.push_back(tmp % 10);
		tmp /= 10;
	}
	arr[2] = Big_Int(tmpvec);
	tmpvec.clear();
	tmp = 1 + a + b + a * a + c + a * b + (b + a * a) * a;
	while (tmp > 0)
	{
		tmpvec.push_back(tmp % 10);
		tmp /= 10;
	}
	arr[3] = Big_Int(tmpvec);
	Big_Int tmpbig;
	for (int i = 4; i <= N; i++)
	{
		Big_Int res = arr[i - 1];
		tmpbig = arr[i - 1].minus(arr[i - 2]);
		tmpbig = tmpbig.mutiply(a_big);
		res = res.plus(tmpbig);
		tmpbig = arr[i - 2].minus(arr[i - 3]);
		tmpbig = tmpbig.mutiply(b_big);
		res = res.plus(tmpbig);
		tmpbig = arr[i - 3];
		tmpbig = tmpbig.mutiply(c_big);
		res = res.plus(tmpbig);
		arr[i] = res;
	}
	cout << arr[n].present();
	return 0;
}