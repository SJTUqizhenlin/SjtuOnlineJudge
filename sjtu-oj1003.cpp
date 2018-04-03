#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int L;
	cin >> L;
	int *dish = new int[L * L];
	queue<int> q1;
	queue<int> q2;
	queue<int> *qcur = &q1;
	queue<int> *qano = &q2;
	queue<int> *tmp = qcur;
	int sum = 0;
	for (int i = 0; i < L * L; i++)
	{
		cin >> dish[i];
		if (dish[i] == 1) qcur->push(i);
		if (dish[i] != 0) sum++;
	}
	int count = 0;
	int cur = -1;
	while (sum < L * L)
	{
		while (!qcur->empty())
		{
			cur = qcur->front();
			qcur->pop();
			if (cur >= L) if (dish[cur - L] == 0) { dish[cur - L] = 1; qano->push(cur - L); sum++; }
			if (cur + L < L * L) if (dish[cur + L] == 0) { dish[cur + L] = 1; qano->push(cur + L); sum++; }
			if (cur % L != 0) if (dish[cur - 1] == 0) { dish[cur - 1] = 1; qano->push(cur - 1); sum++; }
			if ((cur + 1) % L != 0) if (dish[cur + 1] == 0) { dish[cur + 1] = 1; qano->push(cur + 1); sum++; }
		}
		tmp = qano;
		qano = qcur;
		qcur = tmp;

		//for (int i = 0; i < L * L; i++)
		//{
		//	cout << dish[i];
		//}
		//cout << endl;

		count++;
	}
	cout << count << endl;
	return 0;
}