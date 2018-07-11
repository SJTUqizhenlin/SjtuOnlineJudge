#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string s; stringstream ss;
	ss.clear(); getline(cin, s); ss.str(s);
	int T; ss >> T;
	int m, n, tmpint;
	vector<vector<int> > orderv;
	int bitarr[21];
	while (T--)
	{
		orderv.clear();
		ss.clear(); getline(cin, s); ss.str(s);
		ss.clear(); getline(cin, s); ss.str(s);
		ss >> n >> m;
		for (int i = 0; i < m; i++)
		{
			ss.clear(); getline(cin, s); ss.str(s);
			vector<int> avec;
			while (ss >> tmpint) avec.push_back(tmpint);
			orderv.push_back(avec);
		}
		bool isCompat = false;
		for (int i = 0; i < (1 << n); i++)
		{
			int x = i;
			for (int j = 0; j < n; j++)
			{
				bitarr[j] = x % 2;
				x >>= 1;
			}
			bool isOK = true;
			for (int j = 0; j < orderv.size(); j++)
			{
				bool iamOK = (orderv[j].size() == 0);
				for (int k = 0; k < orderv[j].size(); k++)
					if (iamOK = iamOK ||
						(orderv[j][k] > 0 ? bitarr[orderv[j][k] - 1]
							: !bitarr[-orderv[j][k] - 1])) break;
				isOK = isOK && iamOK;
				if (!isOK) break;
			}
			if (isCompat = isCompat || isOK) break;
		}
		if (isCompat) cout << "Bingo!\n"; else cout << "Sigh...\n";
	}
	return 0;
}