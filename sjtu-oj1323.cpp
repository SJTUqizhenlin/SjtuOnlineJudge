#include <iostream>  
#include <string>
#include <vector>
using namespace std;

vector<int> v = 
{
	1246895,
	1248596,
	1249568,
	1258946,
	1426958,
	1496258,
	1526894,
	1596824,
	1824956,
	1842695,
	1849625,
	1894256,
	1942568,
	1946825,
	1948526,
	1958246,
	2415968,
	2461958,
	2468951,
	2485961,
	2495618,
	2495681,
	2518496,
	2519468,
	2561894,
	2568194,
	2581496,
	2589461,
	2619485,
	2689415,
	2695184,
	2695814,
	4152689,
	4159682,
	4256189,
	4256819,
	4269518,
	4269581,
	4612589,
	4619582,
	4682519,
	4689512,
	4852619,
	4859612,
	4956182,
	4956812,
	4962518,
	4962581,
	5124689,
	5184269,
	5184962,
	5194682,
	5261948,
	5268941,
	5618249,
	5618942,
	5681249,
	5681942,
	5814269,
	5814962,
	5824619,
	5894612,
	5961248,
	5968241,
	6124859,
	6125894,
	6182495,
	6189425,
	6194852,
	6195824,
	6251849,
	6258149,
	6812495,
	6819425,
	6824159,
	6825194,
	6894152,
	6895124,
	6951842,
	6958142,
	8124956,
	8142695,
	8149625,
	8194256,
	8241596,
	8246195,
	8249561,
	8251946,
	8426951,
	8496251,
	8526194,
	8596124,
	8941526,
	8942561,
	8946125,
	8951246,
	9415268,
	9425618,
	9425681,
	9461258,
	9468251,
	9485261,
	9512468,
	9518426,
	9561824,
	9568124,
	9581426,
	9582461,
	9612485,
	9625184,
	9625814,
	9682415
};

bool check(int x) {
	string s = to_string(x);
	int len = s.length();
	bool exist[10] = { 0 };
	int p = 0, tot = 0;
	for (int i = 0; i < len; i++){
		p = (p + s[p] - '0') % len;
		if (!exist[s[p] - '0']) ++tot;
		exist[s[p] - '0'] = 1;
	}
	return tot == len;
}

int main() {
	int num, vsize = v.size(); cin >> num;
	if (num >= 974835)
		for (int i = 0; i < vsize; i++) { if (v[i] > num) { cout << v[i] << endl; break; } }
	else
		while (1)
			if (check(++num)) { cout << num << endl; break; }
	return 0;
}