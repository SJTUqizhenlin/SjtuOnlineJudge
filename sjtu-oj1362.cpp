#include <stdio.h>
using namespace std;

void swap(int &x, int &y) { int tmp = x; x = y; y = tmp; }

struct dice
{
	int num[6];
	dice& operator=(const dice &rhs)
	{
		for (int i = 0; i < 6; i++) num[i] = rhs.num[i];
		return *this;
	}
	void adjust(int p1)
	{
		if (p1 == 0) return;
		if (p1 == 1) { swap(num[0], num[1]); swap(num[4], num[5]); return;
		}
		if (p1 == 2) 
		{ 
			int tmp = num[0]; num[0] = num[2]; 
			num[2] = num[1]; num[1] = num[3]; num[3] = tmp; return;
		}
		if (p1 == 3)
		{
			int tmp = num[0]; num[0] = num[3];
			num[3] = num[1]; num[1] = num[2]; num[2] = tmp; return;
		}
		if (p1 == 4)
		{
			int tmp = num[0]; num[0] = num[4];
			num[4] = num[1]; num[1] = num[5]; num[5] = tmp; return;
		}
		if (p1 == 5)
		{
			int tmp = num[0]; num[0] = num[5];
			num[5] = num[1]; num[1] = num[4]; num[4] = tmp; return;
		}
		return;
	}
	bool isSame(const dice &sd)
	{
		if (num[1] != sd.num[1]) return false;
		if (num[2] == sd.num[2] && num[3] == sd.num[3] 
			&& num[4] == sd.num[4] && num[5] == sd.num[5]) return true;
		if (num[2] == sd.num[3] && num[3] == sd.num[2] 
			&& num[4] == sd.num[5] && num[5] == sd.num[4]) return true;
		if (num[2] == sd.num[4] && num[3] == sd.num[5] 
			&& num[4] == sd.num[3] && num[5] == sd.num[2]) return true;
		if (num[2] == sd.num[5] && num[3] == sd.num[4] 
			&& num[4] == sd.num[2] && num[5] == sd.num[3]) return true;
		return false;
	}
};

int main()
{
	int N; scanf("%d", &N);
	dice standard;
	for (int j = 0; j < 6; j++) scanf("%d", &(standard.num[j]));
	dice tmp, acopy;
	int Count = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 6; j++) scanf("%d", &(tmp.num[j]));
		bool res = false;
		for (int j = 0; j < 6; j++)
		{
			if (tmp.num[j] == standard.num[0])
			{
				acopy = tmp;
				acopy.adjust(j);
				if (acopy.isSame(standard))
				{
					res = true;
					break;
				}
			}
		}
		if (res) ++Count;
	}
	printf("%d\n", Count);
	return 0;
}