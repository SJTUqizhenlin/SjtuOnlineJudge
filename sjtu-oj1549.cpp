#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	
	string s; 
	char res[110];
	stack<int> stk;
	while (cin >> s) {
		int leng = s.length();
		for (int i = 0; i < leng; i++) {
			if (s[i] == '(') stk.push(i);
			if (s[i] == ')') {
				if (!stk.empty() && s[stk.top()] == '(')
					stk.pop();
				else stk.push(i);
			}
		}
		for (int i = 0; i < leng; i++) res[i] = ' ';
		res[leng] = '\0';
		while (!stk.empty()) {
			int tmp = stk.top();
			if (s[tmp] == '(') res[tmp] = '$';
			else res[tmp] = '?';
			stk.pop();
		}
		cout << s << endl;
		cout << res << endl;
	}
	return 0;
}