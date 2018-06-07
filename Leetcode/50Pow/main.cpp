#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, double> maps;

double mypow(double x, int n)
{
	if (maps.find(n) != maps.end())
		return maps[n];

	if (n % 2 == 0)
	{
		maps[n] = mypow(x, n / 2) * mypow(x, n / 2);
	}
	else
	{
		maps[n] = mypow(x, n / 2) * mypow(x, n / 2 + 1);
	}
	
	return maps[n];
}

int main()
{
	double x = 4.70975;
	int n = -6;

	if (n == 0)
		return 1;
	if (n == 1)
		return x;

	bool isSigned = false;

	if (n < 0)
	{
		n = -n;
		isSigned = true;
	}

	maps[0] = 1;
	maps[1] = x;
	
	double res = mypow(x, n);
	
	if (isSigned)
		return 1 / res;

		return res;
}