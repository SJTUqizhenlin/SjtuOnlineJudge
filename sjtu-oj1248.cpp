#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

bool func1(vector<string> &src, vector<string> &dst)
{
	vector<string> mid;
	for (int i = 0; i < n; i++) mid.push_back(src[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mid[i][j] = src[n - 1 - j][i];
	bool jud = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mid[i][j] != dst[i][j]) jud = false;
	return jud;
}

bool func2(vector<string> &src, vector<string> &dst)
{
	vector<string> mid;
	for (int i = 0; i < n; i++) mid.push_back(src[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mid[i][j] = src[n - 1 - i][n - 1 - j];
	bool jud = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mid[i][j] != dst[i][j]) jud = false;
	return jud;
}

bool func3(vector<string> &src, vector<string> &dst)
{
	vector<string> mid;
	for (int i = 0; i < n; i++) mid.push_back(src[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mid[i][j] = src[j][n - 1 - i];
	bool jud = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mid[i][j] != dst[i][j]) jud = false;
	return jud;
}
bool func4(vector<string> &src, vector<string> &dst)
{
	vector<string> mid;
	for (int i = 0; i < n; i++) mid.push_back(src[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mid[i][j] = src[i][n - 1 - j];
	bool jud = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mid[i][j] != dst[i][j]) jud = false;
	return jud;
}

bool func5(vector<string> &src, vector<string> &dst)
{
	vector<string> mid;
	for (int i = 0; i < n; i++) mid.push_back(src[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mid[i][j] = src[i][n - 1 - j];
	if (func1(mid, dst)) return true;
	if (func2(mid, dst)) return true;
	if (func3(mid, dst)) return true;
	return false;
}

bool func6(vector<string> &src, vector<string> &dst)
{
	bool jud = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (src[i][j] != dst[i][j]) jud = false;
	return jud;
}

int main()
{
	vector<string> src;
	vector<string> dst;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string srcstr;
		cin >> srcstr;
		src.push_back(srcstr);
	}
	for (int i = 0; i < n; i++)
	{
		string dststr;
		cin >> dststr;
		dst.push_back(dststr);
	}
	if (func1(src, dst)) { cout << "1" << endl; return 0; }
	if (func2(src, dst)) { cout << "2" << endl; return 0; }
	if (func3(src, dst)) { cout << "3" << endl; return 0; }
	if (func4(src, dst)) { cout << "4" << endl; return 0; }
	if (func5(src, dst)) { cout << "5" << endl; return 0; }
	if (func6(src, dst)) { cout << "6" << endl; return 0; }
	cout << "7" << endl;
	return 0;
}