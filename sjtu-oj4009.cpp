#include <iostream>
#include <string>

using namespace std;

int main()
{
	string Source;
	string Mask;
	string s;
	cin >> Source >> Mask;
	for (int a = 2; a <= Source.length(); a++)
	{
		if (Source.length() % a == 0)
		{
			s = "";
			for (int i = 0; i < a; i++)
				for (int j = 0; j < (Source.length() / a); j++)
				{
					s.append(1, Source[j * a + i]);
				}
			if (s == Mask)
			{
				cout << a << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}