#include <vector>
using namespace std;


int main()
{
	vector<int> digits;

	int i = digits.size() - 1;
	for (; i >= 0; i--)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
			continue;
		}
		else
		{
			digits[i] += 1;
			break;
		}
	}

	if (i < 0)
	{
		vector<int> res;
		res.push_back(1);
		for (int j = 0; j < digits.size(); j++)
			res.push_back(digits[j]);
		return res;
	}
	else
		return digits;



}