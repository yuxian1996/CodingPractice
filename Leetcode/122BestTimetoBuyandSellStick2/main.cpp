#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> prices;

	if (prices.size() == 0 || prices.size() == 1)
		return 0;

	int maxProfit = 0;
	int left = prices[0], right = prices[0];
	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i] > right)
			right = prices[i];
		else
		{
			maxProfit += right - left;
			right = left = prices[i];
		}
	}

	maxProfit += right - left;

	return maxProfit;
}
