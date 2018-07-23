#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; int arr[1005];
	cin >> s; int l = s.length();
	for (int i = 0; i < l; i++)
		arr[i] = s[i] - '0';
	int res = 0;
	for (int i = 0; i < l; i++)
		if (arr[i] > 0) {
			res += arr[i]; 
			for (int j = i + 1; j < l; j++)
				if (arr[j] <= arr[i]) arr[j] = 0;
				else arr[j] -= arr[i];
			arr[i] = 0;
		}
	cout << res << endl;
	return 0;
}