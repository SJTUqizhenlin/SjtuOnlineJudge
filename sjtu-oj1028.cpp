#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string si;
	stack<int> st;
	for (int i = 0; i < N; i++)
	{
		cin >> si;
		if (si == "begin")
		{
			if (!st.empty() && st.top() == 3)
			{
				cout << "NO" << endl;
				return 0;
			}
			st.push(1);
		}
		if (si == "end")
		{
			while (!st.empty() && st.top() == 4)
				st.pop();
			if (!st.empty() && st.top() == 1)
				st.pop();
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		if (si == "if")
		{
			if (!st.empty() && st.top() == 3)
			{
				cout << "NO" << endl;
				return 0;
			}
			st.push(3);
		}
		if (si == "then")
		{
			if (st.empty() || st.top() != 3)
			{
				cout << "NO" << endl;
				return 0;
			}
			st.pop();
			st.push(4);
		}
		if (si == "else")
		{
			if (st.empty() || st.top() != 4)
			{
				cout << "NO" << endl;
				return 0;
			}
			st.pop();
		}
	}
	while (!st.empty() && st.top() == 4)
		st.pop();
	if (st.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}