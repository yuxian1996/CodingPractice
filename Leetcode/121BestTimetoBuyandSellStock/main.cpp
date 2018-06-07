#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> prices{ 7,1,5,3,6,4 };

	int min = INT_MAX;
	int maxProfit = 0;

	for (int i = 0; i < prices.size(); ++i)
	{
		if (prices[i] < min)
			min = prices[i];

		int profit = prices[i] - min;
		if (profit > maxProfit)
			maxProfit = profit;
	}

	return maxProfit;
}