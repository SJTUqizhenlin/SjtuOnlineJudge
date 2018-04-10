#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	vector<vector<int> >v;
	for (int i = 0; i < n; i++)
	{
		vector<int> vi;
		getline(cin, s);
		stringstream stream(s);
		int ix;
		while (stream >> ix)
			vi.push_back(ix);
		v.push_back(vi);
	}

	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//		cout << v[i][j] << " ";
	//	cout << endl;
	//}

	vector<vector<int> > sh;
	for (int i = 0; i < n; i++)
	{
		vector<int> vi;
		vi.push_back(i);
		sh.push_back(vi);
	}
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		for (int j = 0; j < sh[a].size(); j++)
			sh[b].push_back(sh[a][j]);
		sh[a].clear();
	}
	for (int i = 0; i < n; i++)
		if (sh[i].size() > 0)
		{
			for (int j = 0; j < sh[i].size(); j++)
				for (int k = 0; k < v[sh[i][j]].size(); k++)
				{
					cout << v[sh[i][j]][k];
					if (j != sh[i].size() - 1 || k != v[sh[i][j]].size() - 1)
						cout << " ";
				}
			break;
		}
	return 0;
}