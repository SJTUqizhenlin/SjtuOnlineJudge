#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> vec;
	map<long long, int> m;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (m.find(tmp) == m.end())
			vec.push_back(tmp);
		m[tmp]++;
	}
	long long ans = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i; j < vec.size(); j++)
		{
			int mul = vec[i] * vec[j] % 100000000;
			if (m.find(mul) != m.end())
			{
				long long part = 1;
				part *= m[vec[i]];
				m[vec[i]]--;
				part *= m[vec[j]];
				m[vec[j]]--;
				part *= m[mul];
				ans += part * (2 - (i == j));
				m[vec[i]]++;
				m[vec[j]]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
