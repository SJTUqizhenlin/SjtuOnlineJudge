#include <stdio.h>
#include <string.h>
using namespace std;

void inputStr(char *s)
{
	char tmp[300];
	scanf("%s", &(tmp[0]));
	int len = strlen(tmp) - 2;
	for (int i = 0; i < len; i++)
		s[i] = tmp[i + 1];
	s[len] = '\0';
	return;
}

void Inv(char *s1, char *s2)
{
	int len = strlen(s1);
	for (int i = 0; i < len; i++)
		s2[i] = s1[len - 1 - i];
	s2[len] = '\0';
	return;
}

bool isSame(char *s1, char *s2, int len)
{
	for (int i = 0; i < len; i++)
		s1[len + i] = s1[i];
	s1[len * 2] = '\0';
	for (int beg = 0; beg < len; beg++)
	{
		int i = 0;
		for (i; i < len; i++)
			if (s1[beg + i] != s2[i])
				break;
		if (i == len) return true;
	}
	return false;
}

int main()
{
	char src[300];
	int n; scanf("%d", &n);
	inputStr(&(src[0]));
	int srclen = strlen(src);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		char ukn1[300];
		char ukn2[300];
		inputStr(&(ukn1[0]));
		if (strlen(ukn1) != srclen) continue;
		Inv(ukn1, ukn2);
		if (isSame(ukn1, src, srclen) || isSame(ukn2, src, srclen))
			res++;
	}
	printf("%d\n", res);
	return 0;
}