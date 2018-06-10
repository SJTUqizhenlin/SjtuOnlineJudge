#include <iostream>
#include <string>

using namespace std;

struct Stack
{
	int *content;
	int size_;
	int index;
	Stack()
	{
		content = new int[4001];
		size_ = 4000;
		index = -1;
	}
	void push(int ele)
	{
		if (index < size_)
		{
			index++;
			content[index] = ele;
		}
	}
	void pop()
	{
		if (index >= 0)
			index--;
	}
	int top()
	{
		if (index >= 0)
			return content[index];
		else return -1;
	}
};

int main()
{
	Stack s;
	string word;
	bool b = true;
	while (cin >> word)
	{
		if (word == "begin")
		{
			if (s.top() == 3) { cout << "Error!"; b = false; break; }
			s.push(1);
		}
		if (word == "end")
		{
			while (s.top() == 5) s.pop();
			if (s.top() == 1) s.pop();
			else { cout << "Error!"; b = false; break; }
		}
		if (word == "if")
		{
			if (s.top() == 3) { cout << "Error!"; b = false; }
			s.push(3);
		}
		if (word == "then")
		{
			if (s.top() == 3)
			{
				s.pop();
				s.push(5);
			}
			else { cout << "Error!"; b = false; break; }
		}
		if (word == "else")
		{
			if (s.top() == 5)
			{
				s.pop();
			}
			else { cout << "Error!"; b = false; break; }
		}
	}
	while (s.top() == 5) s.pop();
	if (b) if (s.index == -1) cout << "Match!"; else cout << "Error!";
	return 0;
}