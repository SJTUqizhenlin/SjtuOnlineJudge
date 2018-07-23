#include <iostream>
#include <string>
#include <vector>
using namespace std;

void parseEmoj(string s, vector<string> &v)
{
	int p = 0, pr = 0; 
	int l = s.length();
	string ss;
	while (p < l)
	{
		if (s[p] == '[')
		{
			pr = p + 1;
			while (pr < l && s[pr] != ']') 
				++pr;
			if (pr < l && pr > p + 1)
			{
				ss = s.substr(p + 1, pr - p - 1);
				v.push_back(ss);
			}
			p = pr;
		}
		++p;
	}
	return;
}

int main()
{
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	//s1 = "[╮][╭][o][~\][/~]  [<][>]";
	//s2 = "[╯][╰][^][-][=][>][<][@][⊙]";
	//s3 = "[Д][▽][_][ε][^]  ...";
	//cout << s1 << endl << s2 << endl << s3 << endl;
	vector<string> hands;
	vector<string> eyes;
	vector<string> mouth;
	parseEmoj(s1, hands); int handslen = hands.size();
	parseEmoj(s2, eyes); int eyeslen = eyes.size();
	parseEmoj(s3, mouth); int mouthlen = mouth.size();
	int K; cin >> K;
	int emoji[5];
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> emoji[j];
		if (emoji[0] > handslen || emoji[0] < 1)
		{
			cout << R"(Are you kidding me? \(`Д´)/)" << endl;
			continue;
		}
		if (emoji[1] > eyeslen || emoji[1] < 1)
		{
			cout << R"(Are you kidding me? \(`Д´)/)" << endl;
			continue;
		}
		if (emoji[2] > mouthlen || emoji[2] < 1)
		{
			cout << R"(Are you kidding me? \(`Д´)/)" << endl;
			continue;
		}
		if (emoji[3] > eyeslen || emoji[3] < 1)
		{
			cout << R"(Are you kidding me? \(`Д´)/)" << endl;
			continue;
		}
		if (emoji[4] > handslen || emoji[4] < 1)
		{
			cout << R"(Are you kidding me? \(`Д´)/)" << endl;
			continue;
		}
		cout << hands[emoji[0] - 1] << "(";
		cout << eyes[emoji[1] - 1];
		cout << mouth[emoji[2] - 1];
		cout << eyes[emoji[3] - 1] << ")";
		cout << hands[emoji[4] - 1] << endl;
	}
	return 0;
}

