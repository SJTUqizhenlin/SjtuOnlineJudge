#include <iostream>

using namespace std;

int main()
{
	int height, chair, n;
	cin >> height >> chair >> n;
	height += chair;
	int count = 0;
	int apple = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> apple;
		if (apple <= height) count++;
	}
	cout << count;
	return 0;
}