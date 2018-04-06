#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void deletedouble(char s[], int len, int &count)
{
	bool b = false;
	int tmp;
	for (int i = 0; i < len - 1; i++)
	{
		tmp = i + 1;
		while (s[tmp] == '0' && tmp < len - 1) tmp++;
		if (s[i] == '(' && s[tmp] == ')')
		{
			s[i] = '0';
			s[i + 1] = '0';
			count -= 2;
			b = true;
		}
	}
	if (b == false) return;
	deletedouble(s, len, count);
}

int main()
{
	int n;
	cin >> n;
	char s[101];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &s[0]);
		int len = strlen(s);
		int count = len;
		deletedouble(s, len, count);
		if (count == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}