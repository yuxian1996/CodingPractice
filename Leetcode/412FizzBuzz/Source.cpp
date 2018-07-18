#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;

	vector<string> res(n);
	for (int i = 0; i < n; ++i)
	{
		if ((i + 1) % 3 == 0)
		{
			if ((i + 1) % 5 == 0)
			{
				res[i] = "FizzBuzz";
			}
			else
				res[i] = "Fizz";
		}
		else if ((i + 1) % 5 == 0)
			res[i] = "Buzz";
		else
			res[i] = to_string(i+1);
	}

	return res;
}