#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums{ 10,9,2,5,3,7,101,18 };

	if (nums.size() == 0)
		return 0;

	// num, length
	vector<int> dp(nums.size(), 1);
	dp[0] = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
			{
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}