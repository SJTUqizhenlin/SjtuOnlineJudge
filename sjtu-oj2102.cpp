#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

inline int toDec(char c) { return (c >= 'a' ? (c - 'a' + 10) : (c - '0')); }
inline char toHex(int n) { return (n < 10 ? (char)('0' + n) : (char)('a' + n - 10)); }
inline bool isNum(char c) { return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')); }
inline int ops(int a, char op, int b) { return (op == '+' ? (a + b) : (a * b)); }

char* IntToHex(int x) {
	char *res = new char[10];
	int b = 0;
	while (x) {
		res[b] = toHex(x % 16);
		x /= 16; b++;
	}
	if (b == 0) { res[0] = '0'; b = 1; }
	res[b] = '\0';
	for (int i = 0; i < b - 1 - i; i++) {
		char tmp = res[i];
		res[i] = res[b - 1 - i];
		res[b - 1 - i] = tmp;
	}
	return res;
}

int HexToInt(char *beg, char *end) {
	char *cur = beg;
	int res = 0;
	while (cur != end) {
		res *= 16;
		res += toDec(*cur);
		cur++;
	}
	return res;
}

void Push_Sym(vector<char> &v1, vector<int> &v2, char c) {
	int a, b; char op;
	if (c == ')') {
		while (v1.back() != '(') {
			op = v1.back();
			v1.pop_back();
			a = v2.back(); v2.pop_back();
			b = v2.back(); v2.pop_back();
			v2.push_back(ops(a, op, b));
		}
		v1.pop_back();
	}
	if (c == '(') { v1.push_back(c); return; }
	if (c == '*') { v1.push_back(c); return; }
	if (c == '+') {
		while (v1.back() == '*') {
			v1.pop_back();
			a = v2.back(); v2.pop_back();
			b = v2.back(); v2.pop_back();
			v2.push_back(ops(a, '*', b));
		}
		v1.push_back(c);
	}
	return;
}

int Calculate(char *s) {
	int slen = strlen(s);
	int beg = 0, end = 0;
	vector<char> v1; v1.clear();
	vector<int> v2; v2.clear();
	Push_Sym(v1, v2, '(');
	while (true) {
		while (beg < slen && *(s + beg) == ' ') ++beg;
		if (beg >= slen) break;
		if (!isNum(*(s + beg))) {
			Push_Sym(v1, v2, *(s + beg));
			beg++;
		}
		else {
			end = beg;
			while (end < slen && isNum(*(s + end))) ++end;
			v2.push_back(HexToInt(s + beg, s + end));
			beg = end;
		}
	}
	Push_Sym(v1, v2, ')');
	return v2.back();
}

int main() {
	char *s = new char[410];
	cin.getline(s, 405);
	int res = Calculate(s);
	char *resstr = IntToHex(res);
	cout << resstr << endl;
	return 0;
}