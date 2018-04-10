#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

using namespace std;

struct oper_set
{
	char symbol;
	int prio;
	oper_set(char c)
	{
		symbol = c;
		if (c == '+' || c == '-') prio = 1;
		if (c == '*' || c == '/') prio = 2;
		if (c == '^') prio = 3;
		if (c == ')') prio = 4;
		if (c == '?') prio = 5;
		if (c == '(') prio = 0;
	}
	void change_to(char c)
	{
		symbol = c;
		if (c == '+' || c == '-') prio = 1;
		if (c == '*' || c == '/') prio = 2;
		if (c == '^') prio = 3;
		if (c == ')') prio = 4;
		if (c == '?') prio = 5;
		if (c == '(') prio = 0;
	}
};

stack<long long> numStack;
stack<oper_set> tokStack;

long long str_to_int(string s)
{
	long long bit = 1;
	long long res = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		res += bit * (s[i] - '0');
		bit *= 10;
	}
	return res;
}

long long powerof(long long a, long long b)
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	long long res = 1;
	for (long long i = 0; i < b; i++)
		res *= a;
	return res;
}

bool isNum(char a)
{
	if (a >= '0' && a <= '9') return true;
	else return false;
}

bool calcu()
{
	long long num1 = numStack.top();
	numStack.pop();
	char c = tokStack.top().symbol;
	tokStack.pop();
	if (c == '?')
	{
		numStack.push(0 - num1);
		return true;
	}
	long long num2 = numStack.top();
	numStack.pop();
	if (c == '+') numStack.push(num1 + num2);
	if (c == '-') numStack.push(num2 - num1);
	if (c == '*') numStack.push(num1 * num2);
	if (c == '/') if (num1 != 0) numStack.push(num2 / num1);
	else
	{
		cout << "Error" << endl;
		return false;
	}
	if (c == '^') numStack.push(powerof(num2, num1));
	return true;
}

int main()
{
	string s = "";
	char buffer;
	while (cin >> buffer)
	{
		if (buffer != ' ') s.append(1, buffer);
	}

	int count_ = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '(' || s[i] == ')') count_++;
	if (count_ % 2 != 0)
	{
		cout << "Error" << endl;
		return 0;
	}

	int beg = 0, ed = 0;
	long long tmp;
	bool bo = true;
	oper_set one_tok('+');

	while (true)
	{
		while (!isNum(s[beg]))
		{
			one_tok.change_to(s[beg]);
			if (s[beg] == '-')
				one_tok.change_to('?');
			tokStack.push(one_tok);
			beg++;
			ed++;

			if (ed == s.length())
			{
				while (!tokStack.empty())
				{
					bo = calcu();
					if (bo == false) return 0;
				}
				break;
			}
		}

		while (ed < s.length() && isNum(s[ed]))
			ed++;
		if (ed > beg)
		{
			tmp = atol(s.substr(beg, ed - beg).c_str());
			numStack.push(tmp);
		}
		beg = ed;

		if (ed == s.length())
		{
			while (!tokStack.empty())
			{
				bo = calcu();
				if (bo == false) return 0;
			}
			break;
		}

		one_tok.change_to(s[beg]);

		while (one_tok.symbol == ')')
		{
			bool flag = true;
			while (!tokStack.empty())
			{
				if (tokStack.top().symbol != '(')
				{
					bo = calcu();
					if (bo == false) return 0;
				}
				else
				{
					tokStack.pop();
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << "Error" << endl;
				return 0;
			}
			beg++;
			ed++;
			if (ed == s.length())
			{
				while (!tokStack.empty())
				{
					bo = calcu();
					if (bo == false) return 0;
				}
				break;
			}

			one_tok.change_to(s[beg]);

		}

		if (ed < s.length())
		{
			while (!tokStack.empty())
			{
				if (one_tok.prio <= tokStack.top().prio)
				{
					bo = calcu();
					if (bo == false) return 0;
				}
				else break;
			}
			tokStack.push(one_tok);
			beg++;
			ed++;
		}
		else
			break;

	}
	cout << numStack.top() << endl;
	return 0;
}