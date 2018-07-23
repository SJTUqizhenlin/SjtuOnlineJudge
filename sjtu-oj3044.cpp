#include <iostream>
using namespace std;

const int MOD = 1000000007;
int resarr[1001];

int main()
{
	int n; cin >> n; 
	resarr[0] = resarr[1] = 1;
	if (n <= 900)
	{
		for (int i = 2; i <= n; i++)
			resarr[i] = resarr[i - 2] + resarr[i / 2];
		cout << resarr[n] << endl;
	}
	else
	{
		for (int i = 2; i <= 900; i++)
			resarr[i] = resarr[i - 2] + resarr[i / 2];
		for (int i = 901; i <= n; i++)
			resarr[i] = (resarr[i - 2] + resarr[i / 2]) % MOD;
		cout << resarr[n] << endl;
	}
	return 0;
}