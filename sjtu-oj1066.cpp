#include <iostream>
#include <string>

using namespace std;

int arr[2001][2001];
int addchar[26];
int delchar[26];

int main()
{
	int n, m;
	cin >> n >> m;
	if (m == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	string name;
	cin >> name;
	for (int i = 0; i < n; i++)
	{
		char tmpchar;
		cin >> tmpchar;
		cin >> addchar[tmpchar - 'a'];
		cin >> delchar[tmpchar - 'a'];
	}
	int tmp = 0;
	for (int i = m - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (name[i] == name[j])
				arr[i][j] = arr[i + 1][j - 1];
			else
			{
				arr[i][j] = arr[i + 1][j] + addchar[name[i] - 'a'];
				tmp = arr[i + 1][j] + delchar[name[i] - 'a'];
				if (tmp < arr[i][j]) arr[i][j] = tmp;
				tmp = arr[i][j - 1] + delchar[name[j] - 'a'];
				if (tmp < arr[i][j]) arr[i][j] = tmp;
				tmp = arr[i][j - 1] + addchar[name[j] - 'a'];
				if (tmp < arr[i][j]) arr[i][j] = tmp;
			}
		}
	}
	cout << arr[0][m - 1] << endl;
	return 0;
}