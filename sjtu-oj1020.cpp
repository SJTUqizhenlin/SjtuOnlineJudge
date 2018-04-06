#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(int n, vector<int> prime_vec)
{
	for (int i = 0; i < prime_vec.size(); i++)
	{
		if (prime_vec[i] > sqrt(n)) break;
		if (n % prime_vec[i] == 0) return false;
	}
	return true;
}

int basic(int &n, int m)
{
	int count = 0;
	while (n % m == 0)
	{
		count++;
		n = n / m;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	int n_save = n;
	vector<int> prime_vec;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (isPrime(i, prime_vec))
		{
			prime_vec.push_back(i);
		}
	}
	vector<int> e_vec;
	vector<int> p_vec;
	for (int i = 0; i < prime_vec.size(); i++)
	{
		if (n % prime_vec[i] == 0)
		{
			e_vec.push_back(prime_vec[i]);
			p_vec.push_back(basic(n, prime_vec[i]));
		}
	}
	if (n > sqrt(n_save) && isPrime(n, prime_vec))
	{
		e_vec.push_back(n);
		p_vec.push_back(1);
	}
	cout << n_save << "=";
	for (int i = 0; i < e_vec.size(); i++)
	{
		cout << e_vec[i] << "(" << p_vec[i] << ")";
	}
	return 0;
}