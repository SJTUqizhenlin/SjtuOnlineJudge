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
		bit_num = 10;
		for (int i = 0; i < bit_num; i++) content.push_back(0);
	}

	Big_Int(string s)
	{
		bit_num = s.length() + 1;
		for (int i = 0; i < bit_num; i++) content.push_back(0);
		if (s.length() >= bit_num) {}
		else
		{
			for (int i = 0; i < s.length(); i++)
			{
				int num = s[s.length() - 1 - i] - '0';
				this->content[i] = num;
			}
		}
	}

	void plus(Big_Int &another)
	{
		if (another.bit_num > this->bit_num)
		{
			for (int k = this->bit_num; k < another.bit_num; k++)
				this->content.push_back(0);
		}
		for (int i = 0; i < bit_num - 1; i++)
		{
			int b = this->content[i] + another.content[i];
			this->content[i] = b % 10;
			this->content[i + 1] += b / 10;
		}
	}

	string present()
	{
		string s;
		int b = bit_num - 1;
		while (this->content[b] == 0 && b > 0)
			b--;
		for (int i = b; b >= 0; b--)
		{
			s.append(1, this->content[b] + '0');
		}
		return s;
	}
};

int main()
{
	string a, b;
	cin >> a >> b;
	a.erase(a.length() - 3, 1);
	b.erase(b.length() - 3, 1);
	Big_Int a_big(a);
	Big_Int b_big(b);
	a_big.plus(b_big);
	string res = a_big.present();
	res.insert(res.length() - 2, 1, '.');
	cout << res;
	return 0;
}