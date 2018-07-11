#include <string>
#include <iostream>
using namespace std;

int main()
{
	string string_tobe_encoding;
	getline(cin, string_tobe_encoding);
	int res_num = 0, str_size = string_tobe_encoding.length();
	for (int i = 0; i < str_size; i++)
	{
		if (string_tobe_encoding[i] == ' ') continue;
		if (string_tobe_encoding[i] <= 'Z')
			res_num += ((string_tobe_encoding[i] - 'A' + 1) * (i + 1));
		else
			res_num += ((string_tobe_encoding[i] - 'a' + 27) * (i + 1));
	}
	cout << res_num << endl;
	return 0;
}