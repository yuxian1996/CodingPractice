#include <vector>
using namespace std;

int main()
{
	vector<int> coins{ 2 };
	int amount = 3;

	if (coins.size() == 0)
	{
		if (amount == 0)
			return 0;
		return -1;
	}

	vector<int> dp(amount + 1, -1);
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)
	{
		int min = INT_MAX;
		for (int j = 0; j < coins.size(); ++j)
		{
			int remain = i - coins[j];
			if (remain >= 0 && dp[remain] != -1)
			{
				if (dp[remain] + 1 < min)
					min = dp[remain] + 1;
			}
		}

		if (min != INT_MAX)
			dp[i] = min;
	}

	return dp[dp.size() - 1];
}