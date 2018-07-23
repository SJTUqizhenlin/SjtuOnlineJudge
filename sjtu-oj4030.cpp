#include <stdio.h>
using namespace std;

int main()
{
	double EofK = 0, PofT = 0, ResNum = 0;
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &PofT);
		EofK = (EofK + 1) * PofT;
		ResNum = ResNum + EofK * 2 - PofT;
	}
	printf("%.6f\n", ResNum);
	return 0;
}