//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory.h>
//using namespace std;
//
//void SplitToWord(string &s, vector<string> &tmpv) {
//	int beg = 0, end = 0, len = s.length();
//	while (1) {
//		while (beg < len && s[beg] == ' ') beg++;
//		if (beg >= len) break;
//		end = beg;
//		while (end < len && s[end] != ' ') end++;
//		tmpv.push_back(s.substr(beg, end - beg));
//		beg = end;
//	} return;
//}
//
//void InputAll(vector<vector<string> > &v, int *maxLeng) {
//	string s;
//	while (1) {
//		getline(cin, s);
//		if (s[0] == '@') break;
//		vector<string> tmpv;
//		SplitToWord(s, tmpv);
//		v.push_back(tmpv);
//		int tmpsize = tmpv.size();
//		for (int i = 0; i < tmpsize; i++)
//			if ((int)tmpv[i].length() > maxLeng[i]) maxLeng[i] = tmpv[i].length();
//	} return;
//}
//
//void OutputAll(vector<vector<string> > &v, int *maxLeng) {
//	int size1 = v.size(), size2, size3;
//	for (int i = 0; i < size1; i++) {
//		size2 = v[i].size();
//		for (int j = 0; j < size2; j++) {
//			size3 = v[i][j].length();
//			cout << v[i][j];
//			if (j < size2 - 1)
//				for (int k = size3; k <= maxLeng[j]; k++) cout << ' ';
//		}
//		cout << endl;
//	} return;
//}
//
//int main() {
//	int T; cin >> T; 
//	while (cin.get() != '\n') {}
//	vector<vector<string> > v;
//	int *maxLeng = new int[1000];
//	while (T--) {
//		v.clear();
//		memset(maxLeng, 0, sizeof(int) * 1000);
//		InputAll(v, maxLeng);
//		OutputAll(v, maxLeng);
//	}
//	return 0;
//}

/*
不知道为什么，上面的这段代码没有过 \(OAO)/
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
string lines[10000];
vector<string> words[10000];
int col_len = 0;
int line_len = 0;
int col_longest[10000];
inline int getMax(int a, int b) {
	return a > b ? a : b;
}

void split(string &str, vector<string> &ws) {
	istringstream iss(str);
	do {
		string word;
		iss >> word;
		ws.push_back(word);
	} while (iss);
	ws.pop_back();
	col_len = getMax(col_len, ws.size());
}
void print_blank(int n) {
	for (int i = 0; i < n; ++i){
		cout << " ";
	}return;
}

int main(int argc, char const *argv[])
{

	int N; cin >> N;
	for (int k = 0; k < N; ++k) {
		col_len = 0, line_len = 0;
		string input;
		memset(col_longest, 0, sizeof(col_longest));
		memset(words, 0, sizeof(col_longest));
		getline(cin, input);
		while (input != "@") {
			if (input != "")
				lines[line_len++] = input;
			getline(cin, input);
		}
		for (int i = 0; i < line_len; ++i)
			split(lines[i], words[i]);
		for (int i = 0; i < col_len; ++i)
		{
			int maxLen = 0;
			for (int j = 0; j < line_len; ++j) if (i < words[j].size())
				maxLen = getMax(maxLen, words[j][i].size());
			col_longest[i] = maxLen;
		}
		for (int i = 0; i < line_len; ++i)
		{
			for (int j = 0; j < words[i].size(); ++j)
			{
				cout << words[i][j] << " ";
				print_blank(col_longest[j] - words[i][j].size());
			}
			cout << endl;
		}
	}
	return 0;
}