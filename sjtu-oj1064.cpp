#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

const int maxHPlen = 1000;
struct HPint
{
	int len;
	int val[maxHPlen];
	HPint()
	{
		len = 1;
		memset(val, 0, sizeof(int) * maxHPlen);
	}
	HPint(string s)
	{
		len = s.length();
		for (int i = 1; i <= len; i++)
			val[i] = s[len - i] - '0';
	}
	HPint operator=(string s)
	{
		len = s.length();
		for (int i = 1; i <= len; i++)
			val[i] = s[len - i] - '0';
		return *this;
	}
	HPint operator+(const HPint &b)
	{
		int i;
		HPint ans;
		for (i = 1; i <= len || i <= b.len || ans.val[i]; i++)
		{
			if (i <= len) ans.val[i] += val[i];
			if (i <= b.len) ans.val[i] += b.val[i];
			ans.val[i + 1] = ans.val[i] / 10;
			ans.val[i] %= 10;
		}
		ans.len = i - 1;
		if (ans.len == 0) ans.len = 1;
		return ans;
	}
	string show()
	{
		string res = "";
		for (int i = len; i >= 1; i--)
			res.append(1, val[i] + '0');
		return res;
	}
};

int main()
{
	//HPint a("998");
	//HPint b("999");
	//cout << (b + HPint("1")).show() << endl;

	int n;
	cin >> n;
	long long *arr = new long long[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[n - 1 - i]);
	int *dp = new int[n];
	for (int i = 0; i < n; i++)
		dp[i] = 0;
	HPint *dp2 = new HPint[n];
	dp[0] = 1;
	dp2[0] = "1";
	for (int i = 1; i < n; i++)
	{
		int lower = 0;
		for (int j = 0; j < i; j++)
			if (arr[j] == arr[i])
				lower = j + 1;
		int maxlen = 0;
		for (int j = lower; j < i; j++)
			if (arr[j] < arr[i])
				if (dp[j] > maxlen) maxlen = dp[j];

		if (maxlen > 0 || lower == 0)
			dp[i] = maxlen + 1;

		if (dp[i] > 0)
		{
			if (dp[i] == 1) dp2[i] = "1";
			else
				for (int j = lower; j < i; j++)
					if (dp[j] == maxlen && arr[j] < arr[i])
						dp2[i]  = dp2[i] + dp2[j];
		}
	}
	int max = 0;
	HPint count;
	for (int i = 0; i < n; i++)
		if (dp[i] > max) max = dp[i];
	for (int i = 0; i < n; i++)
		if (dp[i] == max) count = count + dp2[i];
	cout << max << " " << count.show() << endl;

	//cout << endl;
	//for (int i = 0; i < n; i++)
	//	cout << arr[i] << " ";
	//cout << endl;
	//for (int i = 0; i < n; i++)
	//	cout << dp[i] << "  ";
	//cout << endl;
	//for (int i = 0; i < n; i++)
	//	cout << dp2[i] << "  ";
	//cout << endl;

	return 0;
}