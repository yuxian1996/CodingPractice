#include <vector>
using namespace std;

int main()
{
	int n = 10;

	int res = 0;
	vector<bool> notPrimes(n, false);

	for (int i = 2; i < notPrimes.size(); ++i)
	{
		if (!notPrimes[i])
		{
			++res;
			for (int j = 2; i*j < notPrimes.size(); ++j)
			{
				notPrimes[i*j] = true;
			}
		}
	}

	return res;
}