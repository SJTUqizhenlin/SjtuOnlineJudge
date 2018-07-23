#include <iostream>

using namespace std;

int main()
{
	char str[40], a2[2];
	int i = 0, length = 0, a;
	for (i = 0; i<40; i++) str[i] = '\0';
	cin >> a;
	cin.getline(a2, 1, ' ');
	cin.getline(str, 30, '\n');
	for (i = 0; i<40; i++)
		if (str[i] == '\0') break;
	length = i;
	int *line = new int[length];
	int j;
	if (a >= length || a == 1) { cout << str; return 0; }
	for (i = 0; i<length; i += 2 * a - 2) {
		for (j = 0; j<a - 1; j++) line[i + j] = j + 1;
		for (j; j<2 * a - 2; j++) line[i + j] = 2 * a - j - 1;
	}
	for (i = 0; i<a; i++) {
		for (j = 0; j<length; j++) {
			if (line[j] == i + 1) cout << str[j];
		}
	}
	return 0;
}
