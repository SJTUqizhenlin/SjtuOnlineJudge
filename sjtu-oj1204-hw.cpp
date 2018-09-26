#include <iostream>
#include <string.h>

using namespace std;

class charList {
public:
	char *stuf;
	int len;
	charList() {
		stuf = new char[2005];
		stuf[0] = 0;
		len = 0;
	}
	void assign_as(char *s) {
		int slen = strlen(s);
		for (int i = 0; i < slen; i++) stuf[i] = s[i];
		stuf[slen] = 0;
		len = slen;
	}
	void insert_at_(int pos, char *s) {
		if (pos > len || pos < 0) {
			cout << "Error!" << endl;
			return;
		}
		int slen = strlen(s);
		for (int i = len - 1; i >= pos; i--) stuf[i + slen] = stuf[i];
		for (int i = pos; i < pos + slen; i++) stuf[i] = s[i - pos];
		len += slen;
		stuf[len] = 0;
		return;
	}
	void del_at_(int pos, int count) {
		if (pos + count - 1 >= len || pos < 0) {
			cout << "Error!" << endl;
			return;
		}
		for (int i = pos; i + count < len; i++) stuf[i] = stuf[i + count];
		len -= count;
		stuf[len] = 0;
		return;
	}
};

bool isEnd(char *s) {
	int l = strlen(s);
	for (int i = 0; i < l; i++)
		if (s[i] != '*') return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	charList *arr = new charList[101];
	char *tmp = new char[2005];
	int iarr = 0;
	while (1) {
		cin.getline(tmp, 2003);
		if (isEnd(tmp)) break;
		arr[iarr++].assign_as(tmp);
	}
	char *cm = new char[20];
	int a, b; 
	char *ins_str = new char[2005];
	int del_count;
	while (1) {
		cin >> cm;
		if (cm[0] == 'q') {
			for (int i = 0; i < iarr; i++)
				cout << arr[i].stuf << endl;
			break;
		}
		if (cm[0] == 'i') {
			cin >> a >> b;
			cin.get();
			cin.getline(ins_str, 2005);
			if (a <= 0 || a > iarr) {
				cout << "Error!" << endl;
				continue;
			}
			arr[a - 1].insert_at_(b - 1, ins_str);
		}
		if (cm[0] == 'd') {
			cin >> a >> b >> del_count;
			if (a <= 0 || a > iarr) {
				cout << "Error!" << endl;
				continue;
			}
			arr[a - 1].del_at_(b - 1, del_count);
		}
		if (cm[0] == 'l') {
			cin >> a >> b;
			if (a <= 0 || b > iarr || a > b) {
				cout << "Error!" << endl;
				continue;
			}
			for (int i = a; i <= b; i++)
				cout << arr[i - 1].stuf << endl;
		}
	}
	return 0;
}