#include <iostream>
#include <unordered_map>
#include <vector>
typedef long long LL;
using namespace std;

inline int cubeOf(int x) { return (x * x * x); }

int main() {
	int A[5]; int Limit;
	for (int i = 0; i < 5; i++) cin >> A[i];
	cin >> Limit;
	int plus, vsize;
	unordered_map<int, LL> uomap0; uomap0.clear();
	vector<int> numset0; numset0.clear();
	for (int j = -Limit; j <= Limit; j++) {
		if (j == 0) continue;
		plus = A[0] * cubeOf(j);
		if (uomap0[plus] == 0) numset0.push_back(plus);
		uomap0[plus] += 1;
	}
	unordered_map<int, LL> uomap1; uomap1.clear();
	vector<int> numset1; numset1.clear();
	for (int j = -Limit; j <= Limit; j++) {
		if (j == 0) continue;
		vsize = numset0.size();
		for (int k = 0; k < vsize; k++) {
			plus = numset0[k] + A[1] * cubeOf(j);
			if (uomap1[plus] == 0) numset1.push_back(plus);
			uomap1[plus] += uomap0[numset0[k]];
		}
	}
	unordered_map<int, LL> uomap2; uomap2.clear();
	vector<int> numset2; numset2.clear();
	for (int j = -Limit; j <= Limit; j++) {
		if (j == 0) continue;
		plus = A[2] * cubeOf(j);
		if (uomap2[plus] == 0) numset2.push_back(plus);
		uomap2[plus] += 1;
	}
	unordered_map<int, LL> uomap3; uomap3.clear();
	vector<int> numset3; numset3.clear();
	for (int j = -Limit; j <= Limit; j++) {
		if (j == 0) continue;
		vsize = numset2.size();
		for (int k = 0; k < vsize; k++) {
			plus = numset2[k] + A[3] * cubeOf(j);
			if (uomap3[plus] == 0) numset3.push_back(plus);
			uomap3[plus] += uomap2[numset2[k]];
		}
	}
	LL res = 0; int tar;
	for (int j = -Limit; j <= Limit; j++) {
		if (j == 0) continue;
		tar = -(A[4] * cubeOf(j));
		vsize = numset1.size();
		for (int k = 0; k < vsize; k++)
			res += (uomap1[numset1[k]] * uomap3[tar - numset1[k]]);
	}
	cout << res << endl;
	return 0;
}