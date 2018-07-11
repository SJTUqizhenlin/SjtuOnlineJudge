#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector< pair<string, int> > d;

bool match(string& p, string& s) {
	if (p.size() > s.size()) return false;
	return s.substr(0, p.size()) == p;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		d.push_back(make_pair(s, i));
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < m; i++) {
		int k;
		string pref;
		cin >> k >> pref;
		k--;
		int pos = lower_bound(d.begin(), d.end(), make_pair(pref, 0)) - d.begin();
		int poss = pos + k;
		if (poss < d.size() && match(pref, d[poss].first)) {
			cout << d[poss].second + 1 << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
	return 0;
}
