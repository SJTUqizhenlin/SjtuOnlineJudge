#include <iostream>
#include <string.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	char s[110];
	cin.getline(s, 101);
	cout << s << endl;
	int cntLeft = 0;
	int resVec[110];
	int myStack[110];
	for (int i = 0; i < 110; i++) {
		resVec[i] = 0;
		myStack[i] = 0;
	}
	int stkTop = 0;
	int len = strlen(s);
	for (int i = 1; i <= len; i++) {
		if (s[i - 1] == '(') {
			myStack[stkTop] = i;
			stkTop++;
		}
		if (s[i - 1] == ')') {
			if (stkTop == 0) {
				myStack[stkTop] = (0 - i);
				stkTop++;
			}
			else {
				if (myStack[stkTop - 1] > 0) stkTop--;
				else {
					myStack[stkTop] = (0 - i);
					stkTop++;
				}
			}
		}
	}
	char res[110];
	for (int i = 0; i < len; i++) res[i] = ' ';
	res[len] = '\0';
	for (int i = stkTop - 1; i >= 0; i--) {
		if (myStack[i] > 0) res[myStack[i] - 1] = '$';
		else res[0 - myStack[i] - 1] = '?';
	}
	cout << res << endl;
	return 0;
}