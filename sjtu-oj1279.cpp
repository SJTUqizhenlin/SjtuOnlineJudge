#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

char to_num_chr(char chr)
{
	if (chr == 'A' || chr == 'B' || chr == 'C' || chr == '2') return '2';
	if (chr == 'D' || chr == 'E' || chr == 'F' || chr == '3') return '3';
	if (chr == 'G' || chr == 'H' || chr == 'I' || chr == '4') return '4';
	if (chr == 'J' || chr == 'K' || chr == 'L' || chr == '5') return '5';
	if (chr == 'M' || chr == 'N' || chr == 'O' || chr == '6') return '6';
	if (chr == 'P' || chr == 'R' || chr == 'S' || chr == '7') return '7';
	if (chr == 'T' || chr == 'U' || chr == 'V' || chr == '8') return '8';
	if (chr == 'W' || chr == 'X' || chr == 'Y' || chr == '9') return '9';
	if (chr == 'Q' || chr == 'Z' || chr == '-') return '-';
	return chr;
}

char* reformat(char *chrarr)
{
	char *res = new char[8]; res[7] = '\0'; int rescur = 0;
	while (*chrarr != '\0')
	{
		char nxtchr = to_num_chr(*chrarr);
		if (nxtchr != '-') { res[rescur] = nxtchr; ++rescur; }
		++chrarr;
	}
	return res;
}

struct phnum
{
	char *arr;
	phnum() { arr = new char[8]; }
	void setas(char *val) { for (int i = 0; i < 8; i++) arr[i] = val[i]; }
	bool operator<(const phnum &rhs) const
	{
		for (int i = 0; i < 7; i++)
		{
			if (arr[i] < rhs.arr[i]) return true;
			if (arr[i] > rhs.arr[i]) return false;
		}
		return false;
	}
	bool operator==(const phnum &rhs) const
	{
		for (int i = 0; i < 7; i++) if (arr[i] != rhs.arr[i]) return false;
		return true;
	}
	char* showfm()
	{
		char *res = new char[9]; res[8] = '\0';
		for (int i = 0; i < 3; i++) res[i] = arr[i];
		res[3] = '-';
		for (int i = 4; i < 8; i++) res[i] = arr[i - 1];
		return res;
	}
};

phnum book[100000];

int main()
{
	int n; scanf("%d", &n);
	char *tmp = new char[80];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		book[i].setas(reformat(tmp));
	}
	sort(book, book + n);
	int beg = 0, ed = 0, dplnum = 0;
	while (ed < n)
	{
		while (ed + 1 < n && book[ed + 1] == book[beg]) ++ed;
		if (ed > beg) { printf("%s %d\n", book[beg].showfm(), (ed - beg + 1)); ++dplnum; }
		beg = ed + 1; ed = beg;
	}
	if (dplnum == 0) printf("No duplicates.\n");
	return 0;
}