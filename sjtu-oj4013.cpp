#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

int main() {
	string Beg = "12348765";
	string Tar = "12348765";
	int a;
	for (int i = 0; i < 4; i++) {
		cin >> a; Tar[i] = (char)('0' + a);
	}
	for (int i = 0; i < 4; i++) {
		cin >> a; Tar[7 - i] = (char)('0' + a);
	}
	unordered_map<string, string> uomap;
	uomap[Beg] = "";
	queue<string> qu;
	qu.push(Beg);
	string cur, curres;
	while (uomap.find(Tar) == uomap.end()) {
		cur = qu.front();
		curres = uomap[cur];
		string nxt1 = "12348765";
		for (int i = 0; i < 4; i++) nxt1[i] = cur[i + 4];
		for (int i = 4; i < 8; i++) nxt1[i] = cur[i - 4];
		if (uomap.find(nxt1) == uomap.end()) {
			uomap[nxt1] = curres.append(1, 'A');
			qu.push(nxt1);
		}
		curres = uomap[cur];
		string nxt2 = "12348765";
		for (int i = 1; i < 4; i++) nxt2[i] = cur[i - 1];
		for (int i = 5; i < 8; i++) nxt2[i] = cur[i - 1];
		nxt2[0] = cur[3]; nxt2[4] = cur[7];
		if (uomap.find(nxt2) == uomap.end()) {
			uomap[nxt2] = curres.append(1, 'B');
			qu.push(nxt2);
		}
		curres = uomap[cur];
		string nxt3 = "12348765";
		nxt3[0] = cur[0]; nxt3[3] = cur[3];
		nxt3[4] = cur[4]; nxt3[7] = cur[7];
		nxt3[1] = cur[5]; nxt3[2] = cur[1];
		nxt3[5] = cur[6]; nxt3[6] = cur[2];
		if (uomap.find(nxt3) == uomap.end()) {
			uomap[nxt3] = curres.append(1, 'C');
			qu.push(nxt3);
		}
		qu.pop();
	}
	cout << uomap[Tar].length() << endl;
	cout << uomap[Tar] << endl;
	return 0;
}