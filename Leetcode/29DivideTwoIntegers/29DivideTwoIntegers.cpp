#include <vector>
using namespace std;

int main()
{
	int dividend = INT32_MIN, divisor = 1;

	if (dividend == INT32_MIN && divisor == -1)
		return INT32_MAX;

	bool flag = false;
	if (dividend < 0 && divisor > 0)
	{
		//dividend = -dividend;
		flag = true;
	}
	else if (dividend > 0 && divisor < 0)
	{
		//divisor = -divisor;
		flag = true;
	}

	dividend = -abs(dividend);
	divisor = -abs(divisor);

	int i = 0;
	while (dividend <= divisor)
	{
		dividend -= divisor;
		i++;
	}

	return flag? -i : i;
}