//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int arr[10];
//vector<vector<int> > v;
//
//void change(int n)
//{
//	for (int i = 0; i < v[n].size(); i++)
//	{
//		arr[v[n][i]] = ((arr[v[n][i]] == 12) ? 3 : (arr[v[n][i]] + 3));
//	}
//}
//
//bool judge()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		if (arr[i] != 12) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int i1[4] = { 1, 2, 4, 5 };
//	vector<int> v1(i1, i1 + 4);
//	v.push_back(v1);
//	int i2[3] = { 1, 2, 3 };
//	vector<int> v2(i2, i2 + 3);
//	v.push_back(v2);
//	int i3[4] = { 2, 3, 5, 6 };
//	vector<int> v3(i3, i3 + 4);
//	v.push_back(v3);
//	int i4[3] = { 1,4,7 };
//	vector<int> v4(i4, i4 + 3);
//	v.push_back(v4);
//	int i5[5] = { 2,4,5,6,8 };
//	vector<int> v5(i5, i5 + 5);
//	v.push_back(v5);
//	int i6[3] = { 3,6,9 };
//	vector<int> v6(i6, i6 + 3);
//	v.push_back(v6);
//	int i7[4] = { 4,5,7,8 };
//	vector<int> v7(i7, i7 + 4);
//	v.push_back(v7);
//	int i8[3] = { 7,8,9 };
//	vector<int> v8(i8, i8 + 3);
//	v.push_back(v8);
//	int i9[4] = { 5,6,8,9 };
//	vector<int> v9(i9, i9 + 4);
//	v.push_back(v9);
//
//
//	for (int i = 1; i <= 9; i++)
//		cin >> arr[i];
//
//
//
//}

#include <iostream>
using namespace std;

int clocks[10];//记录输入的
int rot[10]; //记录转动次数

int main(int argc, char const *argv[])
{

	for (int i = 1; i <= 9; ++i) {
		cin >> clocks[i];
	}
	int path[10] = { 0 };

	for (rot[1] = 0; rot[1] < 4; ++rot[1])
		for (rot[2] = 0; rot[2] < 4; ++rot[2])
			for (rot[3] = 0; rot[3] < 4; ++rot[3])
				for (rot[4] = 0; rot[4] < 4; ++rot[4])
					for (rot[5] = 0; rot[5] < 4; ++rot[5])
						for (rot[6] = 0; rot[6] < 4; ++rot[6])
							for (rot[7] = 0; rot[7] < 4; ++rot[7])
								for (rot[8] = 0; rot[8] < 4; ++rot[8])
									for (rot[9] = 0; rot[9] < 4; ++rot[9]) 
									{
										path[1] = (clocks[1] + 3 * (rot[1] + rot[2] + rot[4])) % 12;
										path[2] = (clocks[2] + 3 * (rot[1] + rot[2] + rot[3] + rot[5])) % 12;
										path[3] = (clocks[3] + 3 * (rot[2] + rot[3] + rot[6])) % 12;
										path[4] = (clocks[4] + 3 * (rot[1] + rot[4] + rot[5] + rot[7])) % 12;
										path[5] = (clocks[5] + 3 * (rot[1] + rot[3] + rot[5] + rot[7] + rot[9])) % 12;
										path[6] = (clocks[6] + 3 * (rot[3] + rot[5] + rot[6] + rot[9])) % 12;
										path[7] = (clocks[7] + 3 * (rot[4] + rot[7] + rot[8])) % 12;
										path[8] = (clocks[8] + 3 * (rot[5] + rot[7] + rot[8] + rot[9])) % 12;
										path[9] = (clocks[9] + 3 * (rot[6] + rot[8] + rot[9])) % 12;

										int sum = 0;
										for (int i = 1; i <= 9; ++i)
											sum += path[i];
										if (!sum) 
										{
											for (int i = 1; i <= 9; ++i)
											{
												for (int j = 0; j < rot[i]; ++j)
												{
													cout << i << " ";
												}
											}
											cout << endl;
											return 0;
										}

									}

	return 0;
}