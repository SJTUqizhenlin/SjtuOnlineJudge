#include <stdio.h>
#include <string.h>
using namespace std;

char pattern[260];

int main()
{
	scanf("%s", &pattern[0]);
	int patlen = strlen(&pattern[0]);
	int totalpos = 0, pos, fst = -1, Count = 0, T;
	scanf("%d", &T); bool judge;
	char c; scanf("%c", &c); c = ' ';
	while (T--)
	{
		pos = 0; judge = true;
		while (c == ' ') scanf("%c", &c);
		while (true)
		{
			judge = judge && (pos < patlen && 
				(c - pattern[pos] == 0 || c - pattern[pos] == 32) || c - pattern[pos] == -32);
			pos++;
			totalpos++;
			scanf("%c", &c);
			if (c == ' ' || c == '\n') break;
		}
		if (judge)
		{
			Count++;
			if (fst == -1) fst = totalpos - pos;
		}
	}
	if (Count) printf("%d %d\n", Count, fst);
	else printf("-1\n");
	return 0;
}